#!/raven/bin/php82
<?php
# Requires php82 with openssl and posix extensions
# if arguments are given, they are used as the toplevel ports,
# overriding the master top-level ports list

$SCRIPTDIR = __DIR__;

define ("SUMMARIES", "summary");
define ("DESCRIPTIONS", "description");
define ("DEAD_HOMEPAGES", "deadhome");
define ("TOPLEVEL_PORTS", "toplevel");
define ("HTTP_REDIRECT", "redirect");
define ("VERSION_OVERRIDE", "version");

require_once $SCRIPTDIR . "/keyed-lists.php";
require_once $SCRIPTDIR . "/scrape_gem.php";

# Load databases
ingest_file (SUMMARIES, $SCRIPTDIR);
ingest_file (DESCRIPTIONS, $SCRIPTDIR);
ingest_file (DEAD_HOMEPAGES, $SCRIPTDIR);
ingest_file (HTTP_REDIRECT, $SCRIPTDIR);
ingest_file (VERSION_OVERRIDE, $SCRIPTDIR);
set_top_level_ports (TOPLEVEL_PORTS, $SCRIPTDIR);

# global variables
$namebase_queue = array();
$port_data = array();
$truncated_summaries = array();
$ravensource_directory = "";
$VA = 32;	# single point of change when ruby
$VB = 33;	# series are changed in ravenports
$VC = 34;
$RUBY_VERSION_A = -1;
$RUBY_VERSION_B = -1;
$RUBY_VERSION_C = -1;

# Sets the initial scan list as the top-level ports
function set_initial_queue() {
   global
       $data_toplevel_ports,
       $namebase_queue;

   $namebase_queue = $data_toplevel_ports;
}


# Goes though the queue iteratively until the queue is empty after a pass
# During each pass, dependencies are tracked and added to the queue at the end.
function cycle_through_queue ($force_setting) {
    global
        $port_data,
        $namebase_queue;

    $already_seen = array();
    $local_queue = $namebase_queue;

    while (count($local_queue)) {
        $queue_candidates = array();

        foreach ($local_queue as $namebase) {
            $port_data[$namebase] = scrape_gem_info($namebase, $force_setting);
            if ($port_data[$namebase]["success"]) {
                foreach ($port_data[$namebase]["buildrun"] as $brdep) {
                   $queue_candidates[$brdep] = true;
                }
            } else {
                echo "====================> FAILED TO RETRIEVE: $namebase\n";
            }
            $already_seen[$namebase] = true;
        }
        $unique_queue = array();
        foreach (array_keys($queue_candidates) as $candidate) {
            if (!array_key_exists($candidate, $already_seen)) {
                $unique_queue[$candidate] = true;
            }
        }
        $local_queue = array_keys($unique_queue);
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


# Slurp raven.versions.mk to determine latest ruby version
function set_ruby_version($ravensource) {
    global
        $VA, $VB, $VC,
        $RUBY_VERSION_A,
        $RUBY_VERSION_B,
        $RUBY_VERSION_C;

    $PA = substr($VA, 0, 1) . "[.]" . substr($VA, 1, 1);
    $PB = substr($VB, 0, 1) . "[.]" . substr($VB, 1, 1);
    $PC = substr($VC, 0, 1) . "[.]" . substr($VC, 1, 1);
    $RA = "/RUBY_".$PA."_VERSION=\t([0-9]+)[.]([0-9]+)[.]([0-9]+)/U";
    $RB = "/RUBY_".$PB."_VERSION=\t([0-9]+)[.]([0-9]+)[.]([0-9]+)/U";
    $RC = "/RUBY_".$PC."_VERSION=\t([0-9]+)[.]([0-9]+)[.]([0-9]+)/U";
    $rvm = $ravensource . "/Scripts/Ravenports_Mk/raven.versions.mk";

    $contents = file_get_contents($rvm);
    if ($contents === false) {
        exit ("failed to ingest raven.versions.mk");
    } else {
        if (preg_match($RA, $contents, $matches) == 1) {
            $RUBY_VERSION_A = (int)$matches[1] * 10000 +
                              (int)$matches[2] *   100 +
                              (int)$matches[3];
        }
        if (preg_match($RB, $contents, $matches) == 1) {
            $RUBY_VERSION_B = (int)$matches[1] * 10000 +
                              (int)$matches[2] *   100 +
                              (int)$matches[3];
        }
        if (preg_match($RC, $contents, $matches) == 1) {
            $RUBY_VERSION_C = (int)$matches[1] * 10000 +
                              (int)$matches[2] *   100 +
                              (int)$matches[3];
        }
    }
}


# Given a ruby version ("25, "26, "27", etc) and a minimum version string,
# return True if the port builds on the given version.
function meets_minimum_version_requirement ($RUBYVER, $minimum_ver_string) {
    global
        $VA, $VB, $VC,
        $RUBY_VERSION_A,
        $RUBY_VERSION_B,
        $RUBY_VERSION_C;

    switch ($RUBYVER) {
        case $VA : $ruby_version = $RUBY_VERSION_A; break;
        case $VB : $ruby_version = $RUBY_VERSION_B; break;
        case $VC : $ruby_version = $RUBY_VERSION_C; break;
        default  : exit ("Dev error: unrecognized RUBYVER ($RUBYVER)\n");
    }

    # possible strings:
    # "> X", "> X.Y", ">= X", ">= X.Y.Z", "~> X.Y", "!= X.Y.Z"
    $valid_operators = array (">", ">=", "~>", "!=");
    $parts = explode (" ", $minimum_ver_string);

    if (!in_array($parts[0], $valid_operators)) {
        exit ("Dev error: unrecognized version comparison operator: " .
               $parts[0] . "\n");
    }
    $minver = 0;
    $nexver = 0;
    $verparts = explode (".", trim($parts[1]));
    switch (count($verparts)) {
        case 1:
            $minver = (int)$verparts[0] * 10000;
            $nexver = $minver + 10000;  // doesn't really make sense ..
            break;
        case 2:
            $minver = (int)$verparts[0] * 10000 +
                      (int)$verparts[1] * 100;
            $nexver = (int)$verparts[0] * 10000 +
                      10000;
            break;
        case 3:
            $minver = (int)$verparts[0] * 10000 +
                      (int)$verparts[1] * 100 +
                      (int)$verparts[2];
            $nexver = (int)$verparts[0] * 10000 +
                      (int)$verparts[1] * 100 +
                      100;
            break;
        default:
            exit ("Dev error: too many version parts: $parts[1]\n");
    }
    switch ($parts[0]) {
        case ">":
        case "!=":
            return ($ruby_version > $minver);
            break;
        case ">=":
            return ($ruby_version >= $minver);
            break;
        case "~>":
            return ($ruby_version >= $minver && $ruby_version < $nexver);
            break;
        default:
            return false;
    }
}


# return an array of variants based on meeting minimum ruby version requirements
function determine_variants($namebase, $minversion) {
    global $VA, $VB, $VC;

    $variants = array();
    foreach (array($VA, $VB, $VC) as $V) {
# function no longer filters; always returns full set of variants
# Now variants are marked broken instead of being missing
#        if (meets_minimum_version_requirement($V, $minversion)) {
#            array_push($variants, "v" . $V);
#        }
# The lone exception is racc, which is needed for ruby33+
         if ($namebase == "racc") {
             if ($V == "33" || $V == "34") {
                 array_push($variants, "v" . $V);
             }
         } else {
             array_push($variants, "v" . $V);
         }
    }
    if (empty($variants)) {
        exit("Major issue: ruby-$namebase minimum requirements "
           . "exclude all ruby versions: $minversion\n");
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
        $port_data,
        $truncated_summaries,
        $ravensource_directory;

    $portname = "ruby-" . $namebase;

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
    $tarball     = $port_data[$namebase]["distfile"];
    $license     = $port_data[$namebase]["license"];
    $raw_depends = $port_data[$namebase]["req_comment"];
    $homepage    = sanitize_homepage ($namebase,
                                      $port_data[$namebase]["homepage"]);

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

    $vopts_block = "";
    $buildrun_block = "";
    $comments_block = "";
    $subpackages_block = "";
    $available_options = "";

    # variant-base work
    $variants = determine_variants ($namebase, $port_data[$namebase]["min_ruby"]);
    $variants_block = join(" ", $variants);
    $primo = $variants[0];
    foreach ($variants as $V) {
        $broken = !meets_minimum_version_requirement(
            substr($V, 1), $port_data[$namebase]["min_ruby"]);
        $prereturn = ($V == $primo) ? "" : "\n";
        $comments_block    .= $prereturn . "SDESC[$V]=\t\t$comment ($V)";
        $subpackages_block .= "SPKGS[$V]=\t\tsingle\n";
        $vopts_block       .= "VOPTS[$V]=\t\t";
        foreach ($variants as $Z) {
            $prespace = ($Z == $primo) ? "" : " ";
            $setting  = ($Z == $V) ? "ON" : "OFF";
            $SZ = substr($Z, 1);
            $vopts_block       .= $prespace . "RUBY" . $SZ . "=" . $setting;
        }
        $vopts_block .= "\n";
        $prespace = ($V == $primo) ? "" : " ";
        $SV = substr($V, 1);
        $available_options .= $prespace . "RUBY" . $SV;
        $buildrun_block .= "[RUBY" . $SV . "].USES_ON=\t\t\tgem:$V\n";
        if (count($port_data[$namebase]["buildrun"])) {
            $buildrun_block .= "[RUBY" . $SV . "].BUILDRUN_DEPENDS_ON=\t\t";
            foreach ($port_data[$namebase]["buildrun"] as $DEP) {
                $indent = ($DEP == $port_data[$namebase]["buildrun"][0]) ? "" : "\t\t\t\t\t";
                $buildrun_block .= $indent . "ruby-" . $DEP . ":single:" . $V . "\n";
            }
        }
        if ($broken) {
            $buildrun_block .= "[RUBY" . $SV .
                "].BROKEN_ON=\t\t\tDoes not meet minimum Ruby version requirements\n";
        }
    }

    $specification = <<<EOD
DEF[PORTVERSION]=	$portversion
# ------------------------------------------------------------------------

NAMEBASE=		$portname
VERSION=		$pvbraces
KEYWORDS=		ruby
VARIANTS=		$variants_block
$comments_block
HOMEPAGE=		$homepage
CONTACT=		Ruby_Automaton[ruby@ironwolf.systems]

DOWNLOAD_GROUPS=	main
SITES[main]=		RUBYGEMS/
DISTFILE[1]=		$tarball:main
DIST_SUBDIR=		ruby

$subpackages_block
OPTIONS_AVAILABLE=	$available_options
OPTIONS_STANDARD=	none
$vopts_block
# License listed inside gem specification
# => $license

$raw_depends
DISTNAME=		$namebase-$pvbraces
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
set_ruby_version ($ravensource_directory);

set_initial_queue();
if (!download_latest_specs()) {
    exit("Regeneration failed.\n");
}
$force = in_array("--force", $argv);
cycle_through_queue($force);

echo "Number of scanned ports: " . count($port_data) . "\n";
echo "Generating port directories and fetching ....\n";

foreach (array_keys($port_data) as $namebase) {
    generate_port($namebase);
}

if (count($truncated_summaries)) {
    echo "The following gem ports have summaries that are too long:\n";
    foreach ($truncated_summaries as $namebase) {
        echo "  ruby-" . $namebase . "\n";
    }
}

?>