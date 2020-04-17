#!/raven/bin/php74
<?php
# Requires php74 with openssl extension
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
            $port_data[$namebase]["comment"],
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
    $uses        = "cran gmake";
    $portversion = $port_data[$namebase]["version"];
    $tarball     = $port_data[$namebase]["distfile"];
    $license     = $port_data[$namebase]["license"];
    $homepage    = sanitize_homepage ($namebase,
                                      $port_data[$namebase]["homepage"]);

    # prepare buildrun dependencies
    $SS = ":single:standard\n";
    $buildrun_list = array();
    foreach ($port_data[$namebase]["buildrun"] as $DEP) {
        array_push($buildrun_list, "R-" . $DEP . $SS);
    }

    # Get specification.manual (if it exists)
    $manual_portion = "";
    if (file_exists ($manual_specs)) {
        $lines = file($manual_specs);
        foreach ($lines as $line) {
            if ( strlen($line) > 8
              && substr($line, 0, 8) == "USES=\t\t\t")
            {
                $uses .= " " . trim(substr($line, 8));
            } else if ( strlen($line) > 18
                     && substr($line, 0, 18) == "BUILDRUN_DEPENDS=\t")
            {
                array_push($buildrun_list, trim(substr($line, 18)) . "\n");
            } else {
                if (substr($line, -1) == "\n") {
                    $manual_portion .= $line;
                } else {
                    $manual_portion .= $line . "\n";
                }
            }
        }
    }

    # Other CRAN dependencies (set all as build+run types)
    $buildrun_dependencies = "";
    foreach ($buildrun_list as $DEP) {
        if ($buildrun_dependencies == "") {
            $buildrun_dependencies = "BUILDRUN_DEPENDS=\t" . $DEP;
        }
        else {
            $buildrun_dependencies .= "\t\t\t" . $DEP;
        }
    }

    $specification = <<<EOD
DEF[PORTVERSION]=	$portversion
# ------------------------------------------------------------------------

NAMEBASE=		$portname
VERSION=		$pvbraces
KEYWORDS=		cran
VARIANTS=		standard
SDESC[standard]=	$comment
HOMEPAGE=		$homepage
CONTACT=		CRAN_Automaton[cran@ironwolf.systems]

DOWNLOAD_GROUPS=	main
SITES[main]=		CRAN/src/contrib
DISTFILE[1]=		$tarball:main
DIST_SUBDIR=		CRAN
DF_INDEX=		1

SPKGS[standard]=	single

OPTIONS_AVAILABLE=	none
OPTIONS_STANDARD=	none

# License listed on https://cran.r-project.org/
# => $license

USES=			$uses
DISTNAME=		$namebase
GENERATED=		yes
INSTALL_REQ_TOOLCHAIN=	yes

$buildrun_dependencies

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

define_ravensource();
set_initial_queue();
if (!download_latest_specs()) {
    exit("Regeneration failed.\n");
}
$force = in_array("--force", $argv);
cycle_through_queue($force);

#$port_data["arr-pm"] = scrape_gem_info ("arr-pm", $force);

echo "Number of scanned ports: " . count($port_data) . "\n";
echo "Generating port directories and fetching ....\n";

#var_dump($port_data);

foreach (array_keys($port_data) as $namebase) {
#    generate_port($namebase);
}

if (count($truncated_summaries)) {
    echo "The following gem ports have summaries that are too long:\n";
    foreach ($truncated_summaries as $namebase) {
        echo "  ruby-" . $namebase . "\n";
    }
}

?>