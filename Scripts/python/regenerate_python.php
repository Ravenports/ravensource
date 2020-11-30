#!/raven/bin/php74
<?php
# Requires php74 with openssl, json, and posix extensions
# if arguments are given, they are used as the toplevel ports,
# overriding the master top-level ports list
# Also requires: python 3.8
#                python-setuptools-scm
#                python-setuptools-git

$SCRIPTDIR = __DIR__;

define ("SUMMARIES", "summary");
define ("DESCRIPTIONS", "description");
define ("DEAD_HOMEPAGES", "deadhome");
define ("TOPLEVEL_PORTS", "toplevel");
define ("HTTP_REDIRECT", "redirect");
define ("CORRECTIONS", "depfixes");
define ("LEGACY", "legacy");

require_once $SCRIPTDIR . "/keyed-lists.php";
require_once $SCRIPTDIR . "/scrape_pypi.php";

# Load databases
ingest_file (SUMMARIES, $SCRIPTDIR);
ingest_file (DESCRIPTIONS, $SCRIPTDIR);
ingest_file (DEAD_HOMEPAGES, $SCRIPTDIR);
ingest_file (HTTP_REDIRECT, $SCRIPTDIR);
ingest_file (CORRECTIONS, $SCRIPTDIR);
ingest_file (LEGACY, $SCRIPTDIR);
set_top_level_ports (TOPLEVEL_PORTS, $SCRIPTDIR);

# global variables
$namebase_queue = array();
$port_data = array();
$truncated_summaries = array();
$ravensource_directory = "";
$VA = 38;	# single point of change when python
$VB = 37;	# series are changed in ravenports
$VC = 27;
$PYTHON_VERSION_A = -1;
$PYTHON_VERSION_B = -1;
$PYTHON_VERSION_C = -1;

# Sets the initial scan list as the top-level ports
function set_initial_queue() {
   global
       $data_toplevel_ports,
       $namebase_queue;

   $namebase_queue = $data_toplevel_ports;
}


# Python generator isn't recursive, so we only make one pass.
function cycle_through_queue ($force_setting) {
    global
        $VA, $VB, $VC,
        $port_data,
        $namebase_queue;

    set_up_cache();
    foreach ($namebase_queue as $namebase) {
        $port_data[$namebase] = scrape_python_info ($namebase, $force_setting, $VA, $VB, $VC);
        if (!$port_data[$namebase]["success"]) {
            echo "Error scanning $namebase port\n";
        }
    }
}


# Set ravensource (2 levels higher than Scripts/rubygems)
function define_ravensource () {
   global
       $SCRIPTDIR,
       $ravensource_directory;

   $ravensource_directory = realpath($SCRIPTDIR . "/../..");
}


# Determine bucket directory
function bucket_directory($namebase) {
   $full_hash = sha1 ($namebase);
   return "bucket_" . strtoupper (substr ($full_hash, 0, 2));
}


# Slurp raven.versions.mk to determine latest python version
function set_python_version($ravensource) {
    global
        $VA, $VB, $VC,
        $PYTHON_VERSION_A,
        $PYTHON_VERSION_B,
        $PYTHON_VERSION_C;

    $PA = substr($VA, 0, 1) . "[.]" . substr($VA, 1, 1);
    $PB = substr($VB, 0, 1) . "[.]" . substr($VB, 1, 1);
    $PC = substr($VC, 0, 1) . "[.]" . substr($VC, 1, 1);
    $RA = "/PYTHON_".$PA."_VERSION=\t([0-9]+)[.]([0-9]+)[.]([0-9]+)/U";
    $RB = "/PYTHON_".$PB."_VERSION=\t([0-9]+)[.]([0-9]+)[.]([0-9]+)/U";
    $RC = "/PYTHON_".$PC."_VERSION=\t([0-9]+)[.]([0-9]+)[.]([0-9]+)/U";
    $rvm = $ravensource . "/Scripts/Ravenports_Mk/raven.versions.mk";

    $contents = file_get_contents($rvm);
    if ($contents === false) {
        exit ("failed to ingest raven.versions.mk");
    } else {
        if (preg_match($RA, $contents, $matches) == 1) {
            $PYTHON_VERSION_A = (int)$matches[1] * 10000 +
                                (int)$matches[2] *   100 +
                                (int)$matches[3];
        }
        if (preg_match($RB, $contents, $matches) == 1) {
            $PYTHON_VERSION_B = (int)$matches[1] * 10000 +
                                (int)$matches[2] *   100 +
                                (int)$matches[3];
        }
        if (preg_match($RC, $contents, $matches) == 1) {
            $PYTHON_VERSION_C = (int)$matches[1] * 10000 +
                                (int)$matches[2] *   100 +
                                (int)$matches[3];
        }
    }
}


# Given a python version ("25, "26, "27", etc) and a minimum version string,
# return True if the port builds on the given version.
function meets_version_requirements ($PYVER, $requirements_string) {
    global
        $VA, $VB, $VC,
        $PYTHON_VERSION_A,
        $PYTHON_VERSION_B,
        $PYTHON_VERSION_C;

    switch ($PYVER) {
        case $VA : $py_version = $PYTHON_VERSION_A; break;
        case $VB : $py_version = $PYTHON_VERSION_B; break;
        case $VC : $py_version = $PYTHON_VERSION_C; break;
        default  : exit ("Dev error: unrecognized PYVER ($PYVER)\n");
    }

    # possible strings:
    # ">=2.7", "!=3.0.*", "<4.0", ">3.7.4", "!=3.1.2" (assumed)
    $valid_operators = array (">", ">=", "!=", "<", "<=", "~=");
    $requirements = explode (",", $requirements_string);

    $satisfied = true;
    if ($requirements_string == "none") {
        return $satisfied;
    }
    foreach ($requirements as $requirement) {
        if (empty($requirement)) {
            continue;
        }
        $success = preg_match("/^([<>!~][=]?)[ ]?([0-9][0-9.*]*)/",
                             trim($requirement), $matches);
        if ($success) {
            $operator = $matches[1];
            $target   = $matches[2];
            if (!in_array($operator, $valid_operators)) {
               exit ("Dev error: unrecognized version comparison" .
                     " operator: $operator\n");
            }
        } else {
            exit ("Dev error: failed to match '$requirement' " .
                  "version ($requirements_string)\n");
        }
        $minver = 0;
        $nexver = 0;
        $verparts = explode (".", trim($target));
        # asterisk only appears on 3rd component and only on != operator
        switch (count($verparts)) {
            case 1:
                $minver = (int)$verparts[0] * 10000;
                $nexver = $minver + 10000;  # not used
                break;
            case 2:
                $minver = (int)$verparts[0] * 10000 +
                          (int)$verparts[1] * 100;
                $nexver = (int)$verparts[0] * 10000 +
                          10000;
                break;
            case 3:
                if ($verparts[2] = "*") {
                    $lastpart = 0;
                } else {
                    $lastpart = (int)$verparts[2];
                }
                $minver = (int)$verparts[0] * 10000 +
                          (int)$verparts[1] * 100 +
                          $lastpart;
                $nexver = (int)$verparts[0] * 10000 +
                          (int)$verparts[1] * 100 +
                          100;
                break;
        default:
            exit ("Dev error: too many version parts: $target\n");
        }

        switch ($operator) {
            case ">":
                if (!($py_version > $minver)) {
                    $satisfied = false;
                }
                break;
            case ">=":
                if (!($py_version >= $minver)) {
                    $satisfied = false;
                }
                break;
            case "<":
                if (!($py_version < $minver)) {
                    $satisfied = false;
                }
                break;
            case "<=":
                if (!($py_version <= $minver)) {
                    $satisfied = false;
                }
                break;
            case "~=":
                # This means it probably works for higher but author isn't 100% sure
                # for our purposes, we'll consider it as ">=" rather than limit it
                # to the shown value with is too restricting
                if (!($py_version >= $minver)) {
                    $satisfied = false;
                }
                break;
            case "!=":
                # inverted!  We're satisfied if we *don't* match
                if ($py_version >= $minver && $py_version < $nexvar) {
                    $satisfied = false;
                }
                break;
            default:
                # can't happen
                $satisfied = false;

        }
        if (!$satisfied) {
            break;
        }
    }
    return $satisfied;
}


# return an array of variants based on meeting python version requirements
# Python 2.7 is determined manually
function determine_variants($namebase, $requirements) {
    global $VA, $VB, $VC, $data_legacy;

    $variants = array();
    foreach (array($VA, $VB) as $V) {
        if (meets_version_requirements($V, $requirements)) {
            array_push($variants, "py" . $V);
        }
    }
    if (in_array($namebase, $data_legacy)) {
        if (meets_version_requirements($VC, $requirements)) {
            array_push($variants, "py" . $VC);
        }
    }

    if (empty($variants)) {
        exit("Major issue: python-$namebase version requirements "
           . "exclude all python versions: $requirements\n");
    }
    return $variants;
}


# Generate single port
# creates: specification
#          description/desc.single
# - The distinfo is created separately
# - If specification.manual exists, it's concatenated to end of specification
function generate_port($namebase) {
    global
        $EXTS,
        $EXTPATS,
        $port_data,
        $truncated_summaries,
        $ravensource_directory;

    $portname = "python-" . $namebase;

    $output_directory =
        $ravensource_directory .
        "/" . bucket_directory ($portname) .
        "/" . $portname;

    # create desc.single file
    $descdir = $output_directory . "/descriptions";
    $descfile = $descdir . "/desc.single";
    if (!file_exists($descdir)) {
        mkdir ($descdir, 0755, true);
    }
    file_put_contents (
        $descfile,
        produce_long_description (
            $namebase,
            $port_data[$namebase]["description"]
        )
    );

    # specification filename
    $specfile = $output_directory . "/specification";
    $manual_specs = $specfile . ".manual";

    # Get short description
    $summary = sanitize_summary($namebase, $port_data[$namebase]["comment"]);
    $comment = $summary["summary"];

    # Annotate truncated summary
    if ($summary["truncated"]) {
        array_push($truncated_summaries, $namebase);
    }

    # other template variables
    $pvbraces    = '${PORTVERSION}';
    $portversion = $port_data[$namebase]["version"];
    $license     = $port_data[$namebase]["license"];
    $raw_depends = $port_data[$namebase]["req_comment"];
    $uri         = $port_data[$namebase]["pypi_uri"];
    $fetch_url   = $port_data[$namebase]["fetch_url"];
    $whl_file    = $port_data[$namebase]["wheel_dist"];
    $main_site   = $whl_file ? wheel_site($fetch_url) : "PYPI/" . $uri;
    $homepage    = sanitize_homepage ($namebase,
                                      $port_data[$namebase]["homepage"]);

    # minimize future changes by using pvbraces
    foreach ($EXTS as $key => $ext) {
        $tarball  = str_replace ("-" . $portversion . $ext,
                                 "-" . $pvbraces . $ext,
                                 $port_data[$namebase]["distfile"]);
        $distname = preg_replace ($EXTPATS[$key], "", $tarball);
        if ($whl_file) {
            $distname .= '.dist-info';
        }
        if ($tarball != $port_data[$namebase]["distfile"]) {
            break;
        }
    }

    # sanitize license
    if ($license == "") {
        $license = "Not provided.";
    }

    # Get specification.manual (if it exists)
    $manual_portion = "";
    if (file_exists ($manual_specs)) {
        $lines = file($manual_specs);
        foreach ($lines as $line) {
            if (substr($line, -1) == "\n") {
                $manual_portion .= $line;
            } else {
                $manual_portion .= $line . "\n";
            }
        }
    }

    # variant-base work
    $variants = determine_variants ($namebase, $port_data[$namebase]["min_python"]);
    $variants_block = join(" ", $variants);
    $primo = $variants[0];
    $arg = $whl_file ? ',wheel' : '';
    foreach ($variants as $V) {
        $prereturn = ($V == $primo) ? "" : "\n";
        $VX = strtoupper($V);
        $comments_block    .= $prereturn . "SDESC[$V]=\t\t$comment ($VX)";
        $subpackages_block .= "SPKGS[$V]=\t\tsingle\n";
        $vopts_block       .= "VOPTS[$V]=\t\t";
        foreach ($variants as $Z) {
            $prespace = ($Z == $primo) ? "" : " ";
            $setting  = ($Z == $V) ? "ON" : "OFF";
            $SZ = substr($Z, 2);
            $vopts_block       .= $prespace . "PY" . $SZ . "=" . $setting;
        }
        $vopts_block .= "\n";
        $prespace = ($V == $primo) ? "" : " ";
        $SV = substr($V, 2);
        $available_options .= $prespace . "PY" . $SV;
        $buildrun_block .= "[PY" . $SV . "].USES_ON=\t\t\t\tpython:" . $V . $arg . "\n";
        # Once ravenadm recognizes wheel argument and automatically
        # pulls in python-pip as a build dependency, remove the next section
        # ===============================================
        if ($whl_file) {
            $buildrun_block .= "[PY" . $SV . "].BUILD_DEPENDS_ON=\t\tpython-pip:single:" . $V . "\n";
        }
        # ===============================================
        if (count($port_data[$namebase]["buildrun"])) {
            $buildrun_block .= "[PY" . $SV . "].BUILDRUN_DEPENDS_ON=\t\t";
            foreach ($port_data[$namebase]["buildrun"] as $DEP) {
                $indent = ($DEP == $port_data[$namebase]["buildrun"][0]) ? "" : "\t\t\t\t\t";
                $buildrun_block .= $indent . $DEP . ":single:" . $V . "\n";
            }
        }
        if (count($port_data[$namebase]["justrun_py" . $SV])) {
            $buildrun_block .= "[PY" . $SV . "].RUN_DEPENDS_ON=\t\t\t";
            foreach ($port_data[$namebase]["justrun_py" . $SV] as $DEP) {
                $indent = ($DEP == $port_data[$namebase]["justrun_py" . $SV][0]) ? "" : "\t\t\t\t\t";
                $buildrun_block .= $indent . $DEP . ":single:" . $V . "\n";
            }
        }
    }

    $specification = <<<EOD
DEF[PORTVERSION]=	$portversion
# ------------------------------------------------------------------------

NAMEBASE=		$portname
VERSION=		$pvbraces
KEYWORDS=		python
VARIANTS=		$variants_block
$comments_block
HOMEPAGE=		$homepage
CONTACT=		Python_Automaton[python@ironwolf.systems]

DOWNLOAD_GROUPS=	main
SITES[main]=		$main_site
DISTFILE[1]=		$tarball:main

$subpackages_block
OPTIONS_AVAILABLE=	$available_options
OPTIONS_STANDARD=	none
$vopts_block
# License listed at PyPI
# $license

$raw_depends

DISTNAME=		$distname
GENERATED=		yes

$buildrun_block
$manual_portion
EOD;

    file_put_contents ($specfile, $specification);
    $rout = shell_exec("cd $output_directory && /raven/bin/ravenadm dev distinfo");
    # Don't display anything if there was no distinfo fetch
    if (preg_match ("/^([\S\s]*)?\s?Copying\s.*/U", $rout, $matches)) {
        if (count($matches) > 1) {
            echo $matches[1];
        }
    }
    $rout = shell_exec ("/raven/bin/ravenadm dev buildsheet " .
                        $output_directory . " save");
}

# only root can run this
if (posix_geteuid() != 0) {
    exit ("This script can only be run by the root user.\n");
}

define_ravensource();
set_python_version ($ravensource_directory);

set_initial_queue();
$force = in_array("--force", $argv);
cycle_through_queue($force);

echo "Number of scanned ports: " . count($port_data) . "\n";
echo "Generating port directories and fetching ....\n";

foreach (array_keys($port_data) as $namebase) {
    generate_port($namebase);
}

if (count($truncated_summaries)) {
    echo "The following python ports have summaries that are too long:\n";
    foreach ($truncated_summaries as $namebase) {
        echo "  python-" . $namebase . "\n";
    }
}

?>