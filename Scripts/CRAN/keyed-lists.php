<?php

# Global variables to hold our databases
$data_summary = array();
$data_description = array();
$data_homepage = array();
$data_toplevel_ports = array();
$data_https_redirect = array();


# procedure to set global variables.
# It must be called one for each global variable
# argument 1 must be summary|description|deadhome|toplevel
# argument 2 is the absolute path to this file
function ingest_file ($datatype, $scriptdir) {
    global
        $data_summary,
        $data_description,
        $data_homepage,
        $data_https_redirect,
        $data_toplevel_ports;

    $filename = "";
    $varname = "";

    switch ($datatype) {
        case "summary":
            $filename = "list.summary-override";
            $varname = "data_summary";
            break;
        case "description":
            $filename = "list.description-override";
            $varname = "data_description";
            break;
        case "deadhome":
            $filename = "list.dead-homepage";
            $varname = "data_homepage";
            break;
        case "toplevel":
            $filename = "list.top-level-R-ports";
            $varname = "data_toplevel_ports";
            break;
        case "redirect":
            $filename = "list.https-redirect";
            $varname = "data_https_redirect";
            break;
        default:
            echo "illegal datatype: $datatype\n";
            echo "Must be summary|description|deadhome|toplevel\n";
            return;
    }
    $lines = file($scriptdir . "/" . $filename);
    foreach ($lines as $line) {
        $parts = explode("\t", $line);
        if (count($parts) == 1) {
            array_push ($$varname, trim($line));
        } else {
            $$varname[$parts[0]] = trim($parts[1]);
        }
    }
}


# Given a short description, it strips out common articles and ensures
# The first letter is capitalized
function make_comment ($shortdesc) {
    $copystring = $shortdesc;
    $copystring = preg_replace ("/^A /i", "", $copystring);
    $copystring = preg_replace ("/^An /i", "", $copystring);
    $copystring = preg_replace ("/^The /i", "", $copystring);
    return ucfirst(trim ($copystring));
}


# Returns the summary string to use in the specification
# Argument 1: port's namebase
# Argument 2: Original summary string
# Returns an associative array:   summary   => <50 char max summary>
#                                 truncated => boolean
function sanitize_summary ($namebase, $original_summary) {
    global $data_summary;

    $summary = "";
    $truncated = false;

    if (array_key_exists($namebase, $data_summary)) {
        $summary = trim ($data_summary[$namebase]);
    } else {
        $summary = make_comment($original_summary);
    }
    if (strlen ($summary) < 12) {
        # too short, add garbage to force a truncation alert
        # so that it can be overridden
        $summary .= "##########----------##########----------##########--";
    }
    # strip trailing periods
    $summary =  preg_replace('/[.]*$/', "", $summary);
    $truncated = strlen ($summary) > 50;
    $final_summary = $truncated ? trim(substr($summary, 0, 50)) : $summary;
    return array("summary" => $final_summary, "truncated" => $truncated);
}

# Produces test for long description.
# If there's an override, it uses that raw text,
# otherwise it uses the given description.
# Finally the text is wrapped to 75 columns and returned.
function produce_long_description
  ($namebase,
   $original_comment,
   $original_description) {
    global $data_description;

    $desctext = "";
    if (array_key_exists($namebase, $data_description)) {
        $unixtext = str_replace ('\n', "\n", $data_description[$namebase]);
        $desctext = wordwrap ($unixtext, 75);
    } else {
        # use the same format as cran.r-project.org
        # also strip out any tabs and consecutive spaces
        $clean_short = preg_replace("/\s+/"," ", $original_comment);
        $clean_long  = preg_replace("/\s+/"," ", $original_description);
        $combined = $namebase . ": " . $clean_short
                  . "\n\n" . $clean_long . "\n";
        $desctext = wordwrap ($combined, 75);
    }
    return $desctext;
}


# Changes http:// to https://
function go_secure ($url) {
    return (str_replace("http://", "https://", $url));
}


# Check if given URL triggers repology's permanent redirection warning
function use_https_instead ($url) {
    global $data_https_redirect;

    if ( strlen($url) >= 10
      && substr($url, 0, 7) == "http://" )
    {
        $rest_of_uri = substr($url, 7);
        $components = explode("/", $rest_of_uri);
        # check if more than 2 components -- and if it matches a wildcard
        $subcomponents = explode(".", $components[0]);
        $nsc = count($subcomponents);
        if ($nsc > 2) {
            $testserver = "*."
                        . $subcomponents[$nsc - 2] . "."
                        . $subcomponents[$nsc - 1];
            if (in_array($testserver, $data_https_redirect)) {
                return true;
            }
        }
        return in_array($components[0], $data_https_redirect);
    }
    return false;
}

# Modifies homepage if necessary.
# 1) If the homepage is marked as dead, return "none"
# 2) If the homepage requires redirection, handle that too.
# 3) If there's more than 1 value, take the first one.
function sanitize_homepage ($namebase, $original_homepage) {
    global $data_homepage;

    if ($original_homepage == "UNSET" || $original_homepage == "")
    {
       return "none";
    }

    $hp_parts = explode (",", $original_homepage);
    $hp0 = trim($hp_parts[0]);
    $hp_parts = explode (" ", $hp0);
    $hp1 = trim($hp_parts[0]);
    if (strpos($hp1, "://") !== false) {
        $hp_parts = explode ("://", $hp1);
        $base_homepage = $hp_parts[1];
    } else {
        $base_homepage = $hp1;
    }

    $hplen = strlen($base_homepage);
    foreach ($data_homepage as $deadpage) {
        $deadsize = strlen($deadpage);
        $homepage_len = strlen($base_homepage);
        if ($deadsize <= $homepage_len) {
            if ($deadpage == substr($base_homepage, 0, $deadsize)) {
                return "none";
            }
        }
    }

    if (use_https_instead ($hp1)) {
       return go_secure ($hp1);
    } else {
       return $hp1;
    }
}


# Checks if there are any command-line arguments.
# If there are, they override the top level ports list
function set_top_level_ports($datatype, $scriptdir) {
    global
        $data_toplevel_ports,
        $argc,
        $argv;

    if ($argc > 1) {
        for ($x = 1; $x < $argc; $x++) {
            array_push($data_toplevel_ports, $argv[$x]);
        }
    } else {
        ingest_file($datatype, $scriptdir);
    }
}
?>
