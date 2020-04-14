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

require_once $SCRIPTDIR . "/keyed-lists.php";
require_once $SCRIPTDIR . "/cran_scraper.php";

# Load databases
ingest_file (SUMMARIES, $SCRIPTDIR);
ingest_file (DESCRIPTIONS, $SCRIPTDIR);
ingest_file (DEAD_HOMEPAGES, $SCRIPTDIR);
set_top_level_ports (TOPLEVEL_PORTS, $SCRIPTDIR);

# global variables
$namebase_queue = array();
$port_data = array();

# Sets the initial scan list as the top-level ports
function set_initial_queue() {
   global
       $data_toplevel_ports,
       $namebase_queue;
   
   $namebase_queue = $data_toplevel_ports;
}

# Goes though the queue iteratively until the queue is empty after a pass
# During each pass, dependencies are tracked and added to the queue at the end.
function cycle_through_queue () {
    global
        $port_data,
        $namebase_queue;
    
    $already_seen = array();
    $local_queue = $namebase_queue;
    
    while (count($local_queue)) {
        $queue_candidates = array();
    
        foreach ($local_queue as $namebase) {
            $port_data[$namebase] = scrape_cran_page($namebase);
            if ($port_data[$namebase]["success"]) {
                echo "Retrieved from CRAN: $namebase\n";
                foreach ($port_data[$namebase]["buildrun"] as $brdep) {
                   $queue_candidates[$brdep] = True;
                }
            } else {
                echo "====================> FAILED TO RETRIEVE: $namebase\n";
            }
            $already_seen[$namebase] = True;
        }
        $unique_queue = array();
        foreach (array_keys($queue_candidates) as $candidate) {
            if (!array_key_exists($candidate, $already_seen)) {
                $unique_queue[$candidate] = True;
            }
        }
        $local_queue = array_keys($unique_queue);
    }
}


# var_dump($data_summary);
# var_dump($data_toplevel_ports);

# var_dump (sanitize_summary ("adegraphics", "sdfasdf"));
# var_dump (sanitize_summary ("dne", "The quick brown fox jumped over the obese and blind lazy dogs."));

# var_dump (scrape_cran_page ("caret"));

set_initial_queue();
cycle_through_queue();

echo "Number of scanned ports: " . count($port_data) . "\n";

?>