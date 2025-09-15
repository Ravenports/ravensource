#!/raven/bin/php82
<?php
# Requires php82 with openssl and posix extensions
# if arguments are given, they are used as the toplevel ports,
# overriding the master top-level ports list
# Also requires: python 3.12
#                python-setuptools-scm
#                python-setuptools-git
#                python-setuptools-rust
#                python-pip
#                python-Cython

$SCRIPTDIR = __DIR__;

define ("SUMMARIES", "summary");
define ("DESCRIPTIONS", "description");
define ("DEAD_HOMEPAGES", "deadhome");
define ("TOPLEVEL_PORTS", "toplevel");
define ("HTTP_REDIRECT", "redirect");
define ("CORRECTIONS", "depfixes");
define ("NEW_HOMEPAGES", "newhome");
define ("PRIMARY_SPKGS", "primary");

require_once $SCRIPTDIR . "/keyed-lists.php";
require_once $SCRIPTDIR . "/scrape_pypi.php";

# Load databases
ingest_file (SUMMARIES, $SCRIPTDIR);
ingest_file (DESCRIPTIONS, $SCRIPTDIR);
ingest_file (DEAD_HOMEPAGES, $SCRIPTDIR);
ingest_file (NEW_HOMEPAGES, $SCRIPTDIR);
ingest_file (HTTP_REDIRECT, $SCRIPTDIR);
ingest_file (CORRECTIONS, $SCRIPTDIR);
ingest_file (PRIMARY_SPKGS, $SCRIPTDIR);
set_top_level_ports (TOPLEVEL_PORTS, $SCRIPTDIR);

# global variables
$namebase_queue = array();
$port_data = array();
$truncated_summaries = array();
$no_descriptions = array();
$ravensource_directory = "";
$DUO = array();
$DUO["VA"] = array ("version" => 312, "variant" => "v12");   # single point of change when python
$DUO["VB"] = array ("version" => 313, "variant" => "v13");   # series are changed in ravenports
$PYTHON_VERSION_A = -1;
$PYTHON_VERSION_B = -1;


# Sets the initial scan list as the top-level ports
function set_initial_queue() {
   global
       $data_toplevel_ports,
       $namebase_queue;

   $namebase_queue = $data_toplevel_ports;
}


# Return version when given a variant
function variant_to_version($variant) {
    global $DUO;

    foreach ($DUO as $V) {
        if ($V["variant"] == $variant) {
           return $V["version"];
        }
    }
    return 0;
}


# Python generator isn't recursive, so we only make one pass.
function cycle_through_queue ($force_setting) {
    global
        $DUO,
        $port_data,
        $namebase_queue;

    set_up_cache();
    foreach ($namebase_queue as $namebase) {
        $port_data[$namebase] = scrape_python_info ($namebase, $force_setting, $DUO);
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
        $DUO,
        $PYTHON_VERSION_A,
        $PYTHON_VERSION_B;

    # transitional issue, VA=39 VB=310
    $VAS = strval($DUO["VA"]["version"]);
    $VBS = strval($DUO["VB"]["version"]);

    $PA = substr($VAS, 0, 1) . "[.]" . substr($VAS, 1);
    $PB = substr($VBS, 0, 1) . "[.]" . substr($VBS, 1);
    $RA = "/PYTHON_".$PA."_VERSION=\t([0-9]+)[.]([0-9]+)[.]([0-9]+)/U";
    $RB = "/PYTHON_".$PB."_VERSION=\t([0-9]+)[.]([0-9]+)[.]([0-9]+)/U";

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
    }
}


# Given a python version ("25, "26, "27", etc) and a minimum version string,
# return True if the port builds on the given version.
function meets_version_requirements ($PYVER, $requirements_string) {
    global
        $DUO,
        $PYTHON_VERSION_A,
        $PYTHON_VERSION_B;

    switch ($PYVER) {
        case $DUO["VA"]["version"] : $py_version = $PYTHON_VERSION_A; break;
        case $DUO["VB"]["version"] : $py_version = $PYTHON_VERSION_B; break;
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
                if ($py_version >= $minver && $py_version < $nexver) {
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
    global $DUO;

    $variants = array();
    foreach ($DUO as $V) {
       if (meets_version_requirements($V["version"], $requirements)) {
           array_push($variants, $V["variant"]);
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
#          description/desc.(single|primary)
# - The distinfo is created separately
# - If specification.manual exists, it's concatenated to end of specification
function generate_port($namebase) {
    global
        $EXTS,
        $EXTPATS,
        $port_data,
        $data_primary,
        $no_descriptions,
        $truncated_summaries,
        $ravensource_directory;

    $portname = "python-" . $namebase;

    $output_directory =
        $ravensource_directory .
        "/" . bucket_directory ($portname) .
        "/" . $portname;

    # create desc.single file
    $descdir = $output_directory . "/descriptions";
    $descfile = $descdir . (in_array($portname, $data_primary) ? "/desc.primary" : "/desc.single");
    if (!file_exists($descdir)) {
        mkdir ($descdir, 0755, true);
    }
    $pretty_desc = produce_long_description ($namebase, $port_data[$namebase]["description"]);
    if ($pretty_desc == "\n") {
        array_push($no_descriptions, $namebase);
    }
    file_put_contents (
        $descfile,
        $pretty_desc
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
    $toml_file   = $port_data[$namebase]["toml_dist"];
    $main_site   = $whl_file ? wheel_site($fetch_url) : "PYPI/" . $uri;
    $homepage    = sanitize_homepage ($namebase,
                                      $port_data[$namebase]["homepage"]);

    # minimize future changes by using pvbraces
    foreach ($EXTS as $key => $ext) {
        $tarball  = str_replace ("-" . $portversion . $ext,
                                 "-" . $pvbraces . $ext,
                                 $port_data[$namebase]["distfile"]);
        $distname = preg_replace ($EXTPATS[$key], "", $tarball);
        # Damn
        if (substr($distname, 0, 6) == "eyeD3-") {
            $distname = "eyed3-" . substr($distname, 6);
        }
        if (substr($distname, 0, 19) == "sphinxcontrib_jquery") {
            $distname = "sphinxcontrib.jquery" . substr($distname, 19);
        }
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
    $arg = $whl_file ? ',wheel' : ($toml_file ? ',pep517' : ',sutools');

    $vopts_block = "";
    $buildrun_block = "";
    $comments_block = "";
    $subpackages_block = "";
    $available_options = "";

    foreach ($variants as $V) {
        $num_split_pkg = 0;
        $prereturn = ($V == $primo) ? "" : "\n";
        $SV = variant_to_version($V);
        $SVT = strval($SV);
        $VX = substr($SVT, 0, 1) . "." . substr($SVT, 1);
        $comments_block    .= $prereturn . "SDESC[$V]=\t\t$comment ($VX)";
        if (in_array($portname, $data_primary)) {
            $subpackages_block .= "SPKGS[$V]=\t\tset primary dev\n";
        } else {
            $subpackages_block .= "SPKGS[$V]=\t\tsingle\n";
        }
        $vopts_block       .= "VOPTS[$V]=\t\t";
        foreach ($variants as $Z) {
            $prespace = ($Z == $primo) ? "" : " ";
            $setting  = ($Z == $V) ? "ON" : "OFF";
            $SZ = strval(variant_to_version($Z));
            $vopts_block       .= $prespace . "PY" . $SZ . "=" . $setting;
        }
        $vopts_block .= "\n";
        $prespace = ($V == $primo) ? "" : " ";
        $available_options .= $prespace . "PY" . $SV;

        # SV is 3 characters now.  We need 3 tabs
        $tabs = "\t\t\t";
        $buildrun_block .= "[PY" . $SV . "].USES_ON=" .$tabs . "python:" . $V . $arg . "\n";
        if (count($port_data[$namebase]["build"])) {
            foreach ($port_data[$namebase]["build"] as $DEP) {
                # HACK, REMOVE WHEN PYTHON V12 and V13 are GONE
                if ($DEP == "python-cffi") {
                    if (in_array ($V, array("v12", "v13"))) {
                        $DEP = "python-cffi117";
                    }
                }
                # END HACK
                if (!$num_split_pkg) {
                    $buildrun_block .= "[PY" . $SV . "].BUILD_DEPENDS_ON=\t\t";
                }
                $indent = $num_split_pkg ? "\t\t\t\t\t" : "";
                $buildrun_block .= $indent . $DEP . ":single:" . $V . "\n";
                $num_split_pkg++;
            }
        }
        if (count($port_data[$namebase]["buildrun"])) {
            foreach ($port_data[$namebase]["buildrun"] as $DEP) {
                # HACK, REMOVE WHEN PYTHON V12 and V13 are GONE
                if ($DEP == "python-cffi") {
                    if (in_array ($V, array("v12", "v13"))) {
                        $DEP = "python-cffi117";
                    }
                }
                # END HACK
                if (in_array($DEP, $data_primary)) {
                    if (!$num_split_pkg) {
                       $buildrun_block .= "[PY" . $SV . "].BUILD_DEPENDS_ON=\t\t";
                    }
                    $indent = $num_split_pkg ? "\t\t\t\t\t" : "";
                    $buildrun_block .= $indent . $DEP . ":dev:" . $V . "\n";
                    $num_split_pkg++;
                }
            }
            $buildrun_block .= "[PY" . $SV . "].BUILDRUN_DEPENDS_ON=\t\t";
            foreach ($port_data[$namebase]["buildrun"] as $DEP) {
                $indent = ($DEP == $port_data[$namebase]["buildrun"][0]) ? "" : "\t\t\t\t\t";
                $mainspkg = in_array($DEP, $data_primary) ? ":primary:" : ":single:";
                $buildrun_block .= $indent . $DEP . $mainspkg . $V . "\n";
            }
        }
        if (count($port_data[$namebase]["justrun_" . $V])) {
            $buildrun_block .= "[PY" . $SV . "].RUN_DEPENDS_ON=\t\t\t";
            foreach ($port_data[$namebase]["justrun_" . $V] as $DEP) {
                $indent = ($DEP == $port_data[$namebase]["justrun_" . $V][0]) ? "" : "\t\t\t\t\t";
                $mainspkg = in_array($DEP, $data_primary) ? ":primary:" : ":single:";
                $buildrun_block .= $indent . $DEP . $mainspkg . $V . "\n";
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
DIST_SUBDIR=		python-src

$subpackages_block
OPTIONS_AVAILABLE=	$available_options
OPTIONS_STANDARD=	none
$vopts_block
# License listed at PyPI
# $license

GENERATED=		yes
DISTNAME=		$distname

$raw_depends

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
if (count($no_descriptions)) {
    echo "The following python ports do not have descriptions:\n";
    foreach ($no_descriptions as $namebase) {
        echo "  python-" . $namebase . "\n";
    }
}

?>