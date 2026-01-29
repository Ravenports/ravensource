#!/raven/bin/php82
<?php
# Requires php82 with openssl, json, yaml and posix extensions
# Also requires the *latest* version of one Ravenports perl to be installed
# If arguments are given, they are used as the toplevel ports,
# overriding the master top-level ports list

$SCRIPTDIR = __DIR__;

define ("SUMMARIES", "summary");
define ("DESCRIPTIONS", "description");
define ("DEAD_HOMEPAGES", "deadhome");
define ("TOPLEVEL_PORTS", "toplevel");
define ("HTTP_REDIRECT", "redirect");
define ("VERSION_OVERRIDE", "version");
define ("REMOVE_V", "badv");
define ("OVERWRITE_INDEX", "index");
define ("EXPAND_VERSION", "badactor");

require_once $SCRIPTDIR . "/keyed-lists.php";
require_once $SCRIPTDIR . "/scrape_cpan.php";

# Load databases
ingest_file (SUMMARIES, $SCRIPTDIR);
ingest_file (DESCRIPTIONS, $SCRIPTDIR);
ingest_file (DEAD_HOMEPAGES, $SCRIPTDIR);
ingest_file (HTTP_REDIRECT, $SCRIPTDIR);
ingest_file (REMOVE_V, $SCRIPTDIR);
ingest_file (OVERWRITE_INDEX, $SCRIPTDIR);
ingest_file (VERSION_OVERRIDE, $SCRIPTDIR);
ingest_file (EXPAND_VERSION, $SCRIPTDIR);
set_top_level_ports (TOPLEVEL_PORTS, $SCRIPTDIR);

# global variables
$module_queue = array();
$port_data = array();
$tagged_summaries = array();
$truncated_summaries = array();

# Sets the initial scan list as the top-level ports
function set_initial_queue() {
   global
       $data_toplevel_ports,
       $module_queue;

   $module_queue = $data_toplevel_ports;
}


# Goes though the queue iteratively until the queue is empty after a pass
# During each pass, dependencies are tracked and added to the queue at the end.
function cycle_through_queue ($force_setting) {
    global
        $port_data,
        $module_queue;

    $already_seen = array();
    $local_queue = $module_queue;

    while (count($local_queue)) {
        $queue_candidates = array();

        foreach ($local_queue as $metaname) {
            $tmp = assemble_port_info ($metaname, $force_setting);
            $namebase = $tmp["namebase"];
            $port_data[$namebase] = $tmp;
            if ($port_data[$namebase]["success"]) {
                foreach ($port_data[$namebase]["cascade"] as $metadep => $depname) {
                   $queue_candidates[$metadep] = $depname;
                }
            } else {
                echo "====================> FAILED TO RETRIEVE: $namebase\n";
            }
            $already_seen[$namebase] = true;
        }
        $unique_queue = array();
        foreach ($queue_candidates as $metaname => $depname) {
            if (!array_key_exists($depname, $already_seen)) {
                # this could potential overwrite, e.g.
                # [Unicode::GCString] => perl-Unicode-LineBreak
                # [Unicode::LineBreak] => perl-Unicode-LineBreak
                # that's okay; we only need one metaname to pull in the ravenport
                $unique_queue[$depname] = $metaname;
            }
        }
        $local_queue = array_values($unique_queue);
    }
}


# given version x.y or x.y.z, the y component is right-padded with zeros
# until it's 4 digits long
function expand_version($raw_version, $num_places) {
   $parts = explode(".", $raw_version);
   for ($x = strlen($parts[1]); $x < $num_places; $x++) {
     $parts[1] .= "0";
   }
   return implode(".", $parts);
}


# Generate single port
# creates: specification
#          description/desc.single
# - The distinfo is created separately
# - If specification.manual exists, it's concatenated to end of specification
function generate_port($namebase) {
    global
        $EXTS, $VA, $VB,
        $port_data,
        $tagged_summaries,
        $truncated_summaries,
        $data_version_expand,
        $ravensource_directory;

    $output_directory =
        $ravensource_directory .
        "/" . bucket_directory ($namebase) .
        "/" . $namebase;

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

    # Annotate summary with html tag in it
    if ($summary["tags"]) {
        array_push($tagged_summaries, $namebase);
    }


    # other template variables
    $pvbraces    = '${PORTVERSION}';
    $portversion = $port_data[$namebase]["version"];
    $license     = $port_data[$namebase]["license"];
    $raw_depends = $port_data[$namebase]["req_comment"];
    $port_author = $port_data[$namebase]["cpandir"];
    $raw_depends = $port_data[$namebase]["req_comment"];
    $homepage    = sanitize_homepage ($namebase,
                                      $port_data[$namebase]["homepage"]);

    # minimize future changes by using pvbraces
    $distname = preg_replace ("/-$portversion" . '$/',
                              "-" . $pvbraces,
                              $port_data[$namebase]["pkgname"]);
    foreach ($EXTS as $key => $ext) {
        $tarball  = str_replace ("-" . $portversion . $ext,
                                 "-" . $pvbraces . $ext,
                                 $port_data[$namebase]["distfile"]);

        if ($tarball != $port_data[$namebase]["distfile"]) {
            break;
        }
    }

    # Handle bad perl versions by expanding to 4 places
    # See: https://github.com/repology/repology-rules/issues/697
    if (array_key_exists ($namebase, $data_version_expand)) {
       $places = intval($data_version_expand[$namebase]);
       $portversion = expand_version($portversion, $places);
       $tarball = $port_data[$namebase]["distfile"];
       foreach ($EXTS as $key => $ext) {
          if (str_ends_with ($tarball, $ext)) {
             $distname = substr($tarball, 0, strlen ($tarball) - strlen ($ext));
             break;
          }
       }
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
    $variants = array();
    $varver = array();
    if (!is_core (true, $port_data[$namebase]["metaname"])) {
        array_push ($variants, $VA);
        $varver[$VA] = substr($VA, 0, 1) . "." . substr($VA, 1, 2);
    }
    if (!is_core (false, $port_data[$namebase]["metaname"])) {
        array_push ($variants, $VB);
        $varver[$VB] = substr($VB, 0, 1) . "." . substr($VB, 1, 2);
    }
    $variants_block = join(" ", $variants);
    $primo = $variants[0];
    $usearg = $port_data[$namebase]["pl_builder"];

    $vopts_block = "";
    $buildrun_block = "";
    $comments_block = "";
    $subpackages_block = "";
    $available_options = "";

    foreach ($variants as $V) {
        $prereturn = ($V == $primo) ? "" : "\n";
        $VX = $varver[$V];
        $comments_block    .= $prereturn . "SDESC[$V]=\t\t$comment ($VX)";
        $subpackages_block .= "SPKGS[$V]=\t\tsingle\n";
        $vopts_block       .= "VOPTS[$V]=\t\t";
        foreach ($variants as $Z) {
            $prespace = ($Z == $primo) ? "" : " ";
            $setting  = ($Z == $V) ? "ON" : "OFF";
            $vopts_block       .= $prespace . "PERL_" . $Z . "=" . $setting;
        }
        $vopts_block .= "\n";
        $prespace = ($V == $primo) ? "" : " ";
        $available_options .= $prespace . "PERL_" . $V;
        $buildrun_block .= "[PERL_" . $V . "].USES_ON=\t\t\tperl:$V,$usearg\n";
        if (count($port_data[$namebase]["buildrun"][$V])) {
            $buildrun_block .= "[PERL_" . $V . "].BUILDRUN_DEPENDS_ON=\t\t";
            $count = 0;
            foreach ($port_data[$namebase]["buildrun"][$V] as $DEP) {
                $count++;
                $indent = ($count == 1) ? "" : "\t\t\t\t\t";
                $buildrun_block .= $indent . $DEP . ":single:" . $V . "\n";
            }
        }
        if (count($port_data[$namebase]["justbuild"][$V])) {
            $buildrun_block .= "[PERL_" . $V . "].BUILD_DEPENDS_ON=\t\t";
            $count = 0;
            foreach ($port_data[$namebase]["justbuild"][$V] as $DEP) {
                $count++;
                $indent = ($count == 1) ? "" : "\t\t\t\t\t";
                $buildrun_block .= $indent . $DEP . ":single:" . $V . "\n";
            }
        }
    }

    $specification = <<<EOD
DEF[PORTVERSION]=	$portversion
# ------------------------------------------------------------------------

NAMEBASE=		$namebase
VERSION=		$pvbraces
KEYWORDS=		perl
VARIANTS=		$variants_block
$comments_block
HOMEPAGE=		$homepage
CONTACT=		Perl_Automaton[perl@ironwolf.systems]

DOWNLOAD_GROUPS=	main
SITES[main]=		CPAN/ID:$port_author
DISTFILE[1]=		$tarball:main

$subpackages_block
OPTIONS_AVAILABLE=	$available_options
OPTIONS_STANDARD=	none
$vopts_block
# License listed in CPAN directory:
$license

GENERATED=		yes
SINGLE_JOB=		yes
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

define_ravensource($SCRIPTDIR);
set_perl_versions();
set_core_module_definitions();

if (!download_latest_specs()) {
    exit("Regeneration failed.\n");
}
$force = in_array("--force", $argv);

set_initial_queue();
cycle_through_queue($force);

echo "Number of scanned ports: " . count($port_data) . "\n";
echo "Generating port directories and fetching ....\n";

foreach (array_keys($port_data) as $namebase) {
    generate_port($namebase);
}

if (count($truncated_summaries)) {
    echo "The following cpan ports have summaries that are too long:\n";
    foreach ($truncated_summaries as $namebase) {
        echo "  $namebase\n";
    }
}
if (count($tagged_summaries)) {
    echo "The following cpan ports have summaries containing <text>:\n";
    foreach ($tagged_summaries as $namebase) {
        echo "  $namebase\n";
    }
}
?>
