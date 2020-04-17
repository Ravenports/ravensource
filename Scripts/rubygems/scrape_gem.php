<?php

# Global variables to hold gem database
$GEM_INDEX    = array();
$RUBYEXE      = "/raven/bin/ruby27";
$LATEST_SPECS = "latest_specs.4.8.gz";
$RUBY_WORKDIR = "/tmp/rubygems";


# Downloads the latest rubygem specifications
function download_latest_specs() {
    global
        $RUBY_WORKDIR,
        $LATEST_SPECS;

    $archurl = "http://rubygems.org/" . $LATEST_SPECS;
    $outfile = $RUBY_WORKDIR . "/" . $LATEST_SPECS;

    $output = shell_exec("rm -rf $RUBY_WORKDIR");
    mkdir ($RUBY_WORKDIR, 0755, true);

    if(file_put_contents($outfile, file_get_contents($archurl))) {
        return true;
    } else {
        echo "Failed to download RubyGem specifications";
        return false;
    }
}


# unpack the downloaded gem index and put into a associative array ($GEM_INDEX)
function populate_gem_index() {
    global
        $RUBYEXE,
        $GEM_INDEX,
        $RUBY_WORKDIR,
        $LATEST_SPECS;

    $specfile = $RUBY_WORKDIR . "/" . $LATEST_SPECS;

    $rprog = $RUBYEXE . ' -e "puts Marshal.load(Gem::Util.gunzip(File.read("'
           . $specfile . '")))';

    $uncompressed = shell_exec($rprog);
    $tracker = 0;
    foreach (explode("\n", $uncompressed) as $line) {
        $tracker++;
             if ($tracker == 1) { $software = $line; }
        else if ($tracker == 2) { $version  = $line; }
        else {
            $GEM_INDEX[$software] = $version;
            $tracker = 0;
        }
    }
}

# performs strip_tags, followed by decoding html special chars,
# followed by converting additional html, followed by trim
function strip_all ($raw_text) {
    $result = strip_tags ($raw_text);
    $result = htmlspecialchars_decode ($result);
    $result = str_replace("&ge;", ">=", $result);
    return trim($result);
}

function scrape_gem_info($namebase) {

    $result = array(
        "success"     => false,
        "version"     => "ERROR",
        "comment"     => "ERROR",
        "description" => "ERROR",
        "license"     => "UNSET",
        "homepage"    => "UNSET",
        "distfile"    => "ERROR",
        "buildrun"    => array(),
    );
}

?>
