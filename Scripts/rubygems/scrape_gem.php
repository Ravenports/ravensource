<?php

# Global variables to hold gem database
$GEM_INDEX    = array();
$GEMEXE       = "/raven/bin/gem";
$RUBYEXE      = "/raven/bin/ruby32";
$LATEST_SPECS = "latest_specs.4.8.gz";
$RUBY_CACHE   = "/var/cache/rubygems";
$SPECS_DIR    = $RUBY_CACHE . "/specs";


# Downloads the latest rubygem version index
# Also creates (as necessary) directories to be used later
function download_latest_specs() {
    global
        $SPECS_DIR,
        $RUBY_CACHE,
        $LATEST_SPECS;

    $archurl = "http://rubygems.org/" . $LATEST_SPECS;
    $outfile = $RUBY_CACHE . "/" . $LATEST_SPECS;

    if (!file_exists($RUBY_CACHE)) {
        mkdir ($RUBY_CACHE, 0755, true);
    }
    if (!file_exists($SPECS_DIR)) {
        mkdir ($SPECS_DIR, 0755, true);
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
        $RUBY_CACHE,
        $LATEST_SPECS;

    $specfile = $RUBY_CACHE . "/" . $LATEST_SPECS;
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
    printf ("Downloading %-50s : ", $gemspec);
    if ($force || !file_exists($outfile)) {
        if(file_put_contents($outfile, file_get_contents($gemurl))) {
            echo "successful\n";
            return true;
        } else {
            echo "FAILED!\n";
            return false;
        }
    }
    echo "cached\n";
    return true;
}


# performs removing multiple whitespace followed by trim
function strip_all ($raw_text) {
    $result = preg_replace("/\s+/"," ", $raw_text);
    return trim($result);
}


# Build up dependencies comment.  It's run in 2 passes
# First pass: add runtime dependencies
# Second pass: add development dependencies
function set_dependencies_comment ($data, &$comment) {
    if ($data == "") {
        return;
    }
    foreach (explode ("\n", $data) as $line) {
        if (strlen ($line) > 95) {
           $arr1 = str_split($line, 95);
           foreach ($arr1 as $subline) {
              $comment .= "#   " . $subline . "\n";
           }
        } else {
            $comment .= "#   " . $line . "\n";
        }
    }
}


# convert requirements into buildrun array
# Skip bundler and racc (packaged with ruby in Ravenports)
function set_dependencies ($data, &$storage) {
    if ($data == "") {
        return;
    }
    foreach (explode ("\n", $data) as $line) {
        $parts = explode (" ", trim($line));
        if (in_array ($parts[0], array ("bundler", "rdoc", "irb", "erb"))) {
            continue;
        }

        if (!in_array($parts[0], $storage)) {
            array_push($storage, $parts[0]);
        }
    }
}


# main function to read rubygem spec and extract usable information
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
        "min_ruby"    => "UNSET",
        "distfile"    => "ERROR",
        "buildrun"    => array(),
        "req_comment" => "# Requirements according to gem specification:\n",
    );

    if (array_key_exists($namebase, $GEM_INDEX)) {
        $gem_version = $GEM_INDEX[$namebase];
    } else {
        echo ("MAJOR: '$namebase' not found in GEM_INDEX\n");
        return $result;
    }

    # get gemspec if not cached
    if (!download_gemspec($namebase, $gem_version, $force)) {
        return $result;
    }

    # grab useful information from gemspec
    $gemspec = $namebase . "-" . $gem_version . ".gemspec.rz";

    # squash ruby program
    # The license/licenses field doesn't seem to work as advertised (so skip it)
    $rprogram = <<<EOF
gs = Marshal.load Gem::Util.inflate File.read "$SPECS_DIR/$gemspec"
puts "<minver>";
puts gs.required_ruby_version
puts "</minver>"
puts "<name>".concat(gs.name).concat("</name>")
puts "<version>"
puts gs.version
puts "</version>"
puts "<xsummary>".concat (gs.summary).concat("</xsummary>")
puts "<desc>".concat(gs.description).concat("</desc>")
if !gs.homepage.nil?
   puts "<home>".concat(gs.homepage).concat("</home>")
end
puts "<runtime>"
puts gs.runtime_dependencies
puts "</runtime>"
puts "<devel>"
puts gs.development_dependencies
puts "</devel>"
puts "<dump>"
puts gs.inspect
puts "</dump>"
EOF;
    $oneline = str_replace ("\n", "; ", $rprogram);

    $data = shell_exec($RUBYEXE . " -e '$rprogram'");
    if (preg_match("/<version>($ANY*)<\/version>/U", $data, $matches) == 1) {
        $result["version"] = strip_all($matches[1]);
    }

    if (preg_match("/<xsummary>($ANY*)<\/xsummary>/U", $data, $matches) == 1) {
        $result["comment"] = strip_all($matches[1]);
    }

    if (preg_match("/<desc>($ANY*)<\/desc>/U", $data, $matches) == 1) {
        $result["description"] = $matches[1]; //not strip_all($matches[1]);
    }

    if (preg_match("/<home>($ANY*)<\/home>/U", $data, $matches) == 1) {
        $result["homepage"] = trim($matches[1]);
    }

    if (preg_match("/<minver>($ANY*)<\/minver>/U", $data, $matches) == 1) {
        $result["min_ruby"] = strip_all($matches[1]);
    }

    if (preg_match("/<runtime>($ANY*)<\/runtime>/U", $data, $matches) == 1) {
        set_dependencies_comment (trim($matches[1]), $result["req_comment"]);
        set_dependencies (trim($matches[1]), $result["buildrun"]);
    }

    if (preg_match("/<devel>($ANY*)<\/devel>/U", $data, $matches) == 1) {
        set_dependencies_comment (trim($matches[1]), $result["req_comment"]);
    }

    if (preg_match("/<dump>\s.+@license=[[](.*)[]].+\s<\/dump>/U",
        $data, $matches) == 1) {
        $result["license"] = $matches[1];
    }

    $result["distfile"]    = $namebase . "-" . $gem_version . ".gem";
    $result["success"]     = true;
    return $result;

}

?>
