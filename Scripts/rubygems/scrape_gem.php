<?php

# Global variables to hold gem database
$GEM_INDEX    = array();
$GEMEXE       = "/raven/bin/gem";
$RUBYEXE      = "/raven/bin/ruby27";
$LATEST_SPECS = "latest_specs.4.8.gz";
$RUBY_WORKDIR = "/tmp/rubygems";
$MIRROR_BASE  = "/var/cache/rubygems";
$SPECS_DIR    = $MIRROR_BASE . "/specs";
$REQS_DIR     = $MIRROR_BASE . "/reqs";


# Downloads the latest rubygem version index
# Also creates (as necessary) directories to be used later
function download_latest_specs() {
    global
        $REQS_DIR,
        $SPECS_DIR,
        $RUBY_WORKDIR,
        $LATEST_SPECS;

    $archurl = "http://rubygems.org/" . $LATEST_SPECS;
    $outfile = $RUBY_WORKDIR . "/" . $LATEST_SPECS;

    $output = shell_exec("rm -rf $RUBY_WORKDIR");
    if (!file_exists($RUBY_WORKDIR)) {
        mkdir ($RUBY_WORKDIR, 0755, true);
    }
    if (!file_exists($SPECS_DIR)) {
        mkdir ($SPECS_DIR, 0755, true);
    }
    if (!file_exists($REQS_DIR)) {
        mkdir ($REQS_DIR, 0755, true);
    }
    
    echo "RubyGem specifications : ";
    if(file_put_contents($outfile, file_get_contents($archurl))) {
        echo "Downloaded.\n";
        populate_gem_index();
        return true;
    } else {
        echo "Failed to download RubyGem specifications\n";
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
    $rprog = $RUBYEXE . ' -e \'puts Marshal.load(Gem::Util.gunzip(File.read("'
           . $specfile . '")))\'';

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


# Downloads a gem's specification given its name and version
# The download is skipped if the file already exists unless the
# $force variable is set to true.
function download_gemspec ($namebase, $version, $force) {
    global $SPECS_DIR;

    $gemspec = $namebase . "-" . $version . ".gemspec.rz";
    $outfile = $SPECS_DIR . "/" . $gemspec;
    $gemurl  = "https://rubygems.org/quick/Marshal.4.8/" . $gemspec;
    echo "Downloading $gemspec : ";
    if ($force || !file_exists($outfile)) {
        if(file_put_contents($outfile, file_get_contents($gemurl))) {
            echo "successful\n";
            return true;
        } else {
            echo "Failed!\n";
            return false;
        }
    }
    echo "(cached)\n";
    return true;
}


# Downloads a gem's dependencies given its name and version.
# The download is skipped if the file already exists unless the
# $force variable is set to true
function download_gemspec_requirements ($namebase, $version, $force) {
    global
        $GEMEXE,
        $REQS_DIR;

    $reqfile = $namebase . "-" . $version . ".requirements";
    $outfile = $REQS_DIR . "/" . $reqfile;
    $command = $GEMEXE . " dependency '/^$namebase\$/' --remote --version=$version";

    echo "Downloading requirements for gem $namebase version $version : ";
    if ($force || !file_exists($outfile)) {
        $dependencies = shell_exec($command);
        if (file_put_contents($outfile, $dependencies)) {
            echo "successful\n";
            return true;
        } else {
            echo "Failed!\n";
            return false;
        }
    }
    echo "(cached)\n";
    return true;
}


# performs strip_tags, followed by decoding html special chars,
# followed by converting additional html, followed by trim
function strip_all ($raw_text) {
    $result = strip_tags ($raw_text);
    $result = htmlspecialchars_decode ($result);
    $result = str_replace("&ge;", ">=", $result);
    return trim($result);
}

function scrape_gem_info($namebase, $force) {

    global
        $GEM_INDEX,
        $RUBYEXE,
        $SPECS_DIR;

    $ANY = "[\s\S]";
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
    
    if (array_key_exists($namebase, $GEM_INDEX)) {
        $gem_version = $GEM_INDEX[$namebase];
    } else {
        echo ("MAJOR: $namebase not found in GEM_INDEX\n");
        return $result;
    }
    
    # get gemspec if not cached
    if (!download_gemspec($namebase, $gem_version, $force)) {
        return $result;
    }

    # get gem's dependencies if not cached
    if (!download_gemspec_requirements($namebase, $gem_version, $force)) {
        return $result;
    }
    # grab useful information from gemspec
    $gemspec = $namebase . "-" . $gem_version . ".gemspec.rz";

    # squash ruby program
    $rprogram = <<<EOF
gs = Marshal.load Gem::Util.inflate File.read "$SPECS_DIR/$gemspec"
puts "<minver>";
puts gs.required_ruby_version
puts "</minver>"
puts "<name>".concat(gs.name).concat("</name>")
puts "<version>"
puts gs.version
puts "</version>"
puts "<summary>".concat (gs.summary).concat("</summary>")
puts "<desc>".concat(gs.description).concat("</desc>")
puts "<home>".concat(gs.homepage).concat("</home>")
# license is a disaster (and does not seem to work).  Skip it.
EOF;
    $oneline = str_replace ("\n", "; ", $rprogram);



    $data = shell_exec($RUBYEXE . " -e '$rprogram'");
    if (preg_match("/<version>($ANY*)<\/version>/", $data, $matches) == 1) {
        $result["version"] = trim($matches[1]);
    }

    if (preg_match("/<summary>($ANY*)<\/summary>/", $data, $matches) == 1) {
        $result["comment"] = trim($matches[1]);
    }

    if (preg_match("/<desc>($ANY*)<\/desc>/", $data, $matches) == 1) {
        $result["description"] = trim($matches[1]);
    }

    if (preg_match("/<home>($ANY*)<\/home>/", $data, $matches) == 1) {
        $result["homepage"] = trim($matches[1]);
    }
    
    $result["distfile"] = $namebase . "-" . $gem_version . ".gem";
    $result["success"] = true;
    return $result;

}

?>
