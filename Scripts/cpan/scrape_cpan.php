<?php

# Global variables to hold gem database
$CPAN_INDEX   = array();
$CORE_MODULES = array();
$LATEST_SPECS = "02packages.details.txt";
$CPAN_CACHE   = "/var/cache/cpan";
$SPECS_DIR    = $CPAN_CACHE . "/specs";
$EXTS         = array("tgz" => ".tar.gz", "zip" => ".zip", "tbz" =>".tar.bz2");

$VA           = 538;    # single point of change when perl
$VB           = 540;    # series are changed in ravenports
$ravensource_directory = "";
$PERL_VERSION_A = "";
$PERL_VERSION_B = "";
$PERL_MAJVER_A = "";
$PERL_MAJVER_B = "";


# Set ravensource (2 levels higher than Scripts/cpan)
function define_ravensource ($scriptdir) {
   global $ravensource_directory;

   $ravensource_directory = realpath($scriptdir . "/../..");
}


#Slurp raven.versions.mk to determine latest perl versions
function set_perl_versions() {
    global
        $ravensource_directory,
        $VA, $VB,
        $PERL_MAJVER_A,
        $PERL_MAJVER_B,
        $PERL_VERSION_A,
        $PERL_VERSION_B;

    $PA = substr($VA, 0, 1) . "[.]" . substr($VA, 1, 2);
    $PB = substr($VB, 0, 1) . "[.]" . substr($VB, 1, 2);
    $RA = "/PERL_".$PA."_VERSION=\t([0-9]+)[.]([0-9]+)[.]([0-9]+)/U";
    $RB = "/PERL_".$PB."_VERSION=\t([0-9]+)[.]([0-9]+)[.]([0-9]+)/U";
    $rvm = $ravensource_directory . "/Scripts/Ravenports_Mk/raven.versions.mk";

    $contents = file_get_contents($rvm);
    if ($contents === false) {
        exit ("failed to ingest raven.versions.mk");
    } else {
        if (preg_match($RA, $contents, $matches) == 1) {
            $PERL_VERSION_A = $matches[1] . "." . $matches[2] . "." . $matches[3];
            $PERL_MAJVER_A = $matches[1] . "." . $matches[2];
        }
        if (preg_match($RB, $contents, $matches) == 1) {
            $PERL_VERSION_B = $matches[1] . "." . $matches[2] . "." . $matches[3];
            $PERL_MAJVER_B = $matches[1] . "." . $matches[2];
        }
    }
}


# Unpacks the zipped cpan package list and puts a filtered subset into
# an associative array ($CPAN_INDEX)
function populate_cpan_index() {
    global
        $data_index_overwrite,
        $CPAN_INDEX,
        $CPAN_CACHE,
        $LATEST_SPECS;

    $plainfile = $CPAN_CACHE . "/" . $LATEST_SPECS;
    $specfile = $plainfile . ".gz";

    if (file_exists($plainfile)) {
        unlink($plainfile);
    }
    if (file_exists($specfile)) {
        $command = "cd $CPAN_CACHE && gunzip $specfile";
        $output = shell_exec($command);
    } else {
        exit ($specfile . " does not exist\n");
    }

    # sample output
    # A1z::Html                          0.04  C/CE/CEEJAY/A1z-Html-0.04.tar.gz
    if (file_exists($plainfile)) {
        $fn = fopen($plainfile, "r");
        $line_number = 0;
        $lastone = "";
        $laststem = "";
        while(! feof($fn)) {
            $line_number++;
            $rawline = fgets($fn);
            if ($line_number < 10) {
                continue;
            }
            $matched = preg_match('/(\S*)[\s]+(\S*)[\s]+(\S*)/', $rawline, $data);
            if (!$matched) {
                continue;
            }
            if (array_key_exists($data[1], $data_index_overwrite)) {
                $CPAN_INDEX[$data[1]] = $data_index_overwrite[$data[1]];
            } else {
                $CPAN_INDEX[$data[1]] = $data[3];
            }
        }
    } else {
        exit ("Failed to uncompress $specfile\n");
    }
}


# This routine downloads the latest module list
# Upon success, it calls another routine to filter the 240,000
# line file to store module-level entries in the $CPAN_INDEX
# Also creates (as necessary) directories to be used later
function download_latest_specs() {
    global
        $SPECS_DIR,
        $CPAN_CACHE,
        $LATEST_SPECS;

    $archurl = "http://www.cpan.org/modules/" . $LATEST_SPECS . ".gz";
    $outfile = $CPAN_CACHE . "/" . $LATEST_SPECS . ".gz";

    if (!file_exists($CPAN_CACHE)) {
        mkdir ($CPAN_CACHE, 0755, true);
    }
    if (!file_exists($SPECS_DIR)) {
        mkdir ($SPECS_DIR, 0755, true);
    }

    echo "CPAN package list : ";
    $contents = file_get_contents($archurl);
    if ($contents === false) {
        echo "Failed to download CPAN package list\n";
        return false;
    } else {
        echo "Downloaded.\n";
    }
    $result = file_put_contents($outfile, $contents);
    if ($result === false) {
        echo "Failed to write $outfile\n";
        return false;
    } else {
        populate_cpan_index();
        return true;
    }
}


# Sets up multi-dim array of core modules
function set_core_module_definitions() {
    global
        $CORE_MODULES,
        $VA, $VB,
        $PERL_VERSION_A,
        $PERL_VERSION_B;

    # sample output of corelist
    # AnyDBM_File                                  1.01
    # App::Cpan                                    1.672
    # App::Prove                                   3.42

    $instructions = array ($VA => $PERL_VERSION_A,
                           $VB => $PERL_VERSION_B);

    foreach ($instructions as $V => $PV) {
        $AUTOPERL = substr($V,0,1) . "." . substr($V,1,2);
        $output = shell_exec("env AUTOPERL=$AUTOPERL /raven/bin/corelist -v $PV");
        if (substr($output, 1, 28) == "Module::CoreList has no info") {
            exit($output);
        }
        $counter = 0;
        foreach (explode("\n", $output) as $rawline) {
            $counter++;
            if ($counter < 3) { continue; }
            $matched = preg_match('/(\S*)[\s]+(\S*)/', $rawline, $data);
            if (!$matched) {
                continue;
            }
            $CORE_MODULES[$V][$data[1]] = $data[2];
        }
    }
}


# Returns true if given module for given perl version is core
function is_core ($check_VA, $cpan_metaname) {
    global
        $CORE_MODULES,
        $VA, $VB;

    if ($check_VA) {
        return (array_key_exists($cpan_metaname, $CORE_MODULES[$VA]));
    } else {
        return (array_key_exists($cpan_metaname, $CORE_MODULES[$VB]));
    }
}


# Extracts author and tarball from given input
# example of input: E/ET/ETHER/Moose-2.2012.tar.gz
#                   S/SA/SAXJAZMAN/malware/XML-Malware-0.01.tar.gz
#                   R/RS/RSAVAGE/Tree-DAG_Node-1.31.tgz
function set_namebase_author_tarball ($input, &$namebase, &$author, &$distfile, &$cpandir, &$pkgname) {
    # one-off correction (remove when obsolete)
    if ($input == "G/GB/GBOUGARD/FusionInventory-Agent_2.6.tar.gz") {
echo("FOUND!");
       $input = "G/GB/GBOUGARD/FusionInventory-Agent-2.6.tar.gz";
    } else if ($input == "H/HA/HAARG/Config-Any-0.32.tar.gz") {
       $input = "H/HA/HAARG/Config-Any-0.33.tar.gz";
    }

    $parts    = explode("/", $input);
    $numparts = count($parts);
    $author   = $parts[2];
    $distfile = $parts[$numparts - 1];
    $cpandir  = implode("/", array_slice ($parts, 0, $numparts - 1));

    $tarparts = explode("-", $distfile);
    $numparts = count($tarparts);
    $namebase = "perl-" . implode("-", array_slice($tarparts, 0, $numparts - 1));

    $tarparts = explode(".", $distfile);
    $numparts = count($tarparts);
    if (substr($tarparts[$numparts - 1], 0, 1) == "t") {
        $pkgname  = implode(".", array_slice($tarparts, 0, $numparts - 1));
    } else {
        $pkgname  = implode(".", array_slice($tarparts, 0, $numparts - 2));
    }
}


# Given a perl module name, return the equivalent ravenport namebase
function get_namebase ($perlmod) {
    global
        $data_index_overwrite,
        $CPAN_INDEX;

    if (array_key_exists($perlmod, $CPAN_INDEX)) {
        $payload = $CPAN_INDEX[$perlmod];
    } else {
        if (array_key_exists($perlmod, $data_index_overwrite)) {
            $payload = $data_index_overwrite[$perlmod];
        } else {
            exit("$perlmod not found in CPAN_INDEX\n");
        }
    }
    $parts    = explode("/", $payload);
    $numparts = count($parts);
    $distfile = $parts[$numparts - 1];

    $tarparts = explode("-", $distfile);
    $numparts = count($tarparts);
    return "perl-" . implode("-", array_slice($tarparts, 0, $numparts - 1));
}


# Downloads the meta file (if one exists) and the Build.PL file (if one exists)
# These are cached, so if they've already been retrieved, it's set in the
# metaformat file which can be scanned to avoid unnecessary fetching.
function download_metaspec($force, $author, $pkgname, &$metaformat) {
    global $SPECS_DIR;

    $urlstub = "https://fastapi.metacpan.org/source/" . $author . "/" . $pkgname;
    $cache_dir = $SPECS_DIR . "/" . $author . "/" . $pkgname;
    $format_file = $cache_dir . "/metaformat";
    if ($force) {
        # blow away cache directory first (if it exists)
        if (file_exists($cache_dir)) {
            $output = shell_exec ("rm -rf $cache_dir");
        }
    }
    if (file_exists($format_file)) {
        $metaformat = file_get_contents($format_file);
        if ($metaformat === false) {
            exit ("download_metaspec: failed to read $format_file\n");
        }
        printf("Downloading %-58s : %s\n", $pkgname, "cached");
        return true;
    }
    # There's no format file, so the information's not yet been retrieved
    if (!file_exists($cache_dir)) {
        mkdir($cache_dir, 0755, true);
    }

    # Fetch Build.PL if it exists
    try {
        $build_pl = $urlstub . "/Build.PL";
        $build = @file_get_contents($build_pl);
    } catch (Exception $e) {
        # do nothing
    }
    if ($build !== false) {
        file_put_contents ($cache_dir . "/Build.PL", $build);
    }

    # search for meta.json, then meta.yaml, then assume nothing
    $meta_json = $urlstub . "/META.json";
    $meta_yaml = $urlstub . "/META.yml";
    try {
        $meta = @file_get_contents($meta_json);
    } catch (Exception $e) {
        # do nothing
    }
    if ($meta === false) {
        try {
            $meta = @file_get_contents($meta_yaml);
        } catch (Exception $e) {
            # do nothing
        }
        if ($meta === false) {
            $metaformat = "nometa";
            printf("Downloading %-58s : %s\n", $pkgname, "No meta");
        } else {
            file_put_contents ($cache_dir . "/META.yml", $meta);
            $metaformat = "yaml";
            printf("Downloading %-58s : %s\n", $pkgname, "META.yml");
        }
    } else {
        file_put_contents ($cache_dir . "/META.json", $meta);
        $metaformat = "json";
        printf("Downloading %-58s : %s\n", $pkgname, "META.json");
    }
    file_put_contents ($format_file, $metaformat);
    return true;
}


# sets the perl builder actions based on contents of build.PL (if it exists)
function set_builder_action($author, $pkgname, &$builder) {
    global $SPECS_DIR;

    $builder = "configure";
    $cache_dir = $SPECS_DIR . "/" . $author . "/" . $pkgname;
    $builder_file = $cache_dir . "/Build.PL";

    if (!file_exists($builder_file)) {
        return;
    }
    $contents = file_get_contents($builder_file);
    if ($contents !== false) {
        if (strpos($contents, "Module::Build::Tiny") === false) {
            $builder = "buildmod,run";
        } else {
            $builder = "buildmodtiny,run";
        }
    }
}


# Determine bucket directory
function bucket_directory($namebase) {
   $full_hash = sha1 ($namebase);
   return "bucket_" . strtoupper (substr ($full_hash, 0, 2));
}


# Use META.json to finish populating port data
function finish_port_json (&$port) {
    global $VA, $VB,
        $PERL_MAJVER_A,
        $PERL_MAJVER_B,
        $SPECS_DIR,
        $CORE_MODULES,
        $data_remove_version,
        $data_version_override,
        $ravensource_directory;

    $portdir = $ravensource_directory . "/"
             . bucket_directory($port["namebase"])
             . "/" . $port["namebase"];
    $cache_dir = $SPECS_DIR . "/" . $port["author"] . "/" . $port["pkgname"];
    $metafile = $cache_dir . "/META.json";
    $json_string = file_get_contents ($metafile);
    $obj = json_decode($json_string, false, 512, JSON_INVALID_UTF8_IGNORE);
    if (is_null($obj)) {
        exit ("Failed to decode $metafile");
    }

    # set version
    if (array_key_exists($port["namebase"], $data_version_override)) {
        $port["version"] = $data_version_override[$port["namebase"]];
    } else {
        if (property_exists ($obj, "version")) {
            if (substr($obj->version, 0, 1) == "v") {
                $port["version"] = substr($obj->version, 1);
            } else {
                $port["version"] = $obj->version;
            }
        }
    }

    # set homepage
    $port["homepage"] = "none";
    if (property_exists($obj, "homepage")) {
        $port["homepage"] = $obj->homepage;
    } else {
        if (property_exists($obj, "resources")) {
            if (property_exists ($obj->resources, "repository")) {
                if (property_exists ($obj->resources->repository, "web")) {
                    $web = $obj->resources->repository->web;
                    if (substr($web, 0, 4) == "http") {
                        $port["homepage"] = $web;
                    }
                } elseif (property_exists ($obj->resources->repository, "url")) {
                    if (substr($obj->resources->repository->url, 0, 4) == "http") {
                        $port["homepage"] = $obj->resources->repository->url;
                    }
                }
            }
        }
    }

    # set license
    if (property_exists($obj, "license")) {
        $port["license"] = "# " . implode (", ", $obj->license);
    } else {
        $port["license"] = "# Not provided in META.json";
    }

    # set descriptions
    if (property_exists($obj, "abstract")) {
        $port["comment"]     = $obj->abstract;
        $port["description"] = $obj->abstract;
    }

    # set dependencies
    if (!property_exists($obj, "prereqs")) {
        $port["req_comment"] = "# This perl port has no dependencies at all.\n";
        return;
    }

    $port["req_comment"] = "# ----------------------------------------------\n" .
                           "# |   Prerequisites extracted from META.json\n" .
                           "# ----------------------------------------------\n";
    $perlverkeys = array();
    $reqs_level = array("requires");
    if (!file_exists($portdir . "/block_meta_recommends")) {
        array_push($reqs_level, "recommends");
    }
    if (!file_exists($portdir . "/broken_$VA")) {
        array_push($perlverkeys, $VA);
    }
    if (!file_exists($portdir . "/broken_$VB")) {
        array_push($perlverkeys, $VB);
    }
    $map = array ($VA => $PERL_MAJVER_A,
                  $VB => $PERL_MAJVER_B);

    foreach (array("runtime", "build", "configure", "test") as $cat) {
        foreach ($reqs_level as $level) {
            if (property_exists ($obj->prereqs, $cat)) {
                if (property_exists ($obj->prereqs->$cat, $level)) {
                    $reqs = $obj->prereqs->$cat->$level;
                    $props = get_object_vars($reqs);
                    ksort($props);
                    foreach ($props as $key => $version) {
                        if ($key == "perl") { continue; }
                        $suff = "";
                        foreach ($perlverkeys as $perlkey) {
                            if (array_key_exists($key, $CORE_MODULES[$perlkey])) {
                                $suff .= " (perl " . $map[$perlkey] . " core)";
                            } else {
                                $depname = get_namebase($key);
                                if ($depname == $port["namebase"]) {
                                    # You can't depend on yourself
                                    continue;
                                }
                                if (file_exists($portdir . "/IGNORE_" . $key)) {
                                    # bad requirement signal manually, ignore
                                    continue;
                                }
                                switch ($cat) {
                                    case "runtime":
                                        $port["cascade"][$key] = $depname;
                                        if (!in_array($depname, $port["buildrun"][$perlkey])) {
                                            array_push($port["buildrun"][$perlkey], $depname);
                                        }
                                        # if listed as build already, remove it there
                                        if (in_array($depname, $port["justbuild"][$perlkey])) {
                                            $ndx = array_search($depname, $port["justbuild"][$perlkey]);
                                            unset($port["justbuild"][$perlkey][$ndx]);
                                        }
                                        break;
                                    case "configure":
                                    case "build":
                                        $port["cascade"][$key] = $depname;
                                        if (!in_array($depname, $port["buildrun"][$perlkey])
                                         && !in_array($depname, $port["justbuild"][$perlkey])) {
                                            array_push($port["justbuild"][$perlkey], $depname);
                                        }
                                        break;
                                }
                            }
                        }
                        $port["req_comment"] .= sprintf ("# | %12s : %s%s\n", $cat, $key, $suff);
                    }
                }
            }
        }
    }
}


# Use META.yml to finish populating port data
function finish_port_yaml (&$port) {
    global $VA, $VB,
        $PERL_VERSION_A,
        $PERL_VERSION_B,
        $SPECS_DIR,
        $CORE_MODULES,
        $data_remove_version,
        $data_version_override,
        $ravensource_directory;

    $portdir = $ravensource_directory . "/"
             . bucket_directory($port["namebase"])
             . "/" . $port["namebase"];
    $cache_dir = $SPECS_DIR . "/" . $port["author"] . "/" . $port["pkgname"];
    $metafile = $cache_dir . "/META.yml";
    $yaml_string = file_get_contents ($metafile);
    $obj = yaml_parse($yaml_string);
    if (is_null($obj)) {
        exit ("Failed to decode $metafile");
    }

    # set version from tarball.  $obj["version"] is untrustworthy
    if (array_key_exists($port["namebase"], $data_version_override)) {
        $port["version"] = $data_version_override[$port["namebase"]];
    } else {
        $tarparts = explode("-", $port["pkgname"]);
        $numparts = count($tarparts);
        $tmpversion = $tarparts[$numparts - 1];
        if (substr($tmpversion, 0, 1) == "v") {
            $port["version"] = substr($tmpversion, 1);
        } else {
            $port["version"] = $tmpversion;
        }
    }

    # set homepage
    $port["homepage"] = "none";
    if (array_key_exists("homepage", $obj)) {
        $port["homepage"] = $obj["homepage"];
    } else {
        if (array_key_exists("resources", $obj)) {
            if (array_key_exists("repository", $obj["resources"])) {
                # normally a string, but it could be an array
                $rrt = gettype ($obj["resources"]["repository"]);
                $web = "nada";
                if ($rrt == "string") {
                    $web = $obj["resources"]["repository"];
                } elseif ($rrt == "array" && array_key_exists("web", $obj["resources"]["repository"])) {
                    $web = $obj["resources"]["repository"]["web"];
                }
                if (substr($web, 0, 4) == "http") {
                    $port["homepage"] = $web;
                }
            }
        }
    }

    # set license
    if (array_key_exists("license", $obj) && !empty($obj["license"])) {
        $port["license"] = "# " . $obj["license"];
    } else {
        $port["license"] = "# Not provided in META.yml";
    }

    # set descriptions
    if (array_key_exists("abstract", $obj)) {
        $port["comment"]     = $obj["abstract"];
        $port["description"] = $obj["abstract"];
    }

    $port["req_comment"] = "# ---------------------------------------------\n" .
                           "# |   Prerequisites extracted from META.yml\n" .
                           "# ---------------------------------------------\n";
    $perlverkeys = array();
    $reqs_level = array("configure_requires", "build_requires", "requires");
    if (!file_exists($portdir . "/block_meta_recommends")) {
        array_push($reqs_level, "recommends");
    }
    if (!file_exists($portdir . "/broken_$VA")) {
        array_push($perlverkeys, $VA);
    }
    if (!file_exists($portdir . "/broken_$VB")) {
        array_push($perlverkeys, $VB);
    }
    $map = array ($VA => $PERL_VERSION_A,
                  $VB => $PERL_VERSION_B);

    foreach ($reqs_level as $cat) {
        if (array_key_exists($cat, $obj) && is_array($obj[$cat])) {
            $props = $obj[$cat];
            ksort($props);
            foreach ($props as $key => $version) {
                $key = trim($key);
                $version = is_null($version) ? "0" : trim($version);
                if ($key == "perl") { continue; }
                $suff = "";
                foreach ($perlverkeys as $perlkey) {
                    if (array_key_exists($key, $CORE_MODULES[$perlkey])) {
                        $suff .= " (perl " . $map[$perlkey] . " core)";
                    } else {
                    $depname = get_namebase($key);
                    if ($depname == $port["namebase"]) {
                        # You can't depend on yourself
                        continue;
                    }
                    if (file_exists($portdir . "/IGNORE_" . $key)) {
                        # bad requirement signal manually, ignore
                        continue;
                    }
                    switch ($cat) {
                        case "requires":
                        case "recommends":
                            $port["cascade"][$key] = $depname;
                            if (!in_array($depname, $port["buildrun"][$perlkey])) {
                                array_push($port["buildrun"][$perlkey], $depname);
                            }
                            # if listed as build already, remove it there
                            if (in_array($depname, $port["justbuild"][$perlkey])) {
                                $ndx = array_search($depname, $port["justbuild"][$perlkey]);
                                unset($port["justbuild"][$perlkey][$ndx]);
                            }
                            break;
                        case "configure_requires":
                        case "build_requires":
                            $port["cascade"][$key] = $depname;
                            if (!in_array($depname, $port["buildrun"][$perlkey])
                             && !in_array($depname, $port["justbuild"][$perlkey])) {
                                array_push($port["justbuild"][$perlkey], $depname);
                            }
                            break;
                        }
                    }
                }
                $port["req_comment"] .= sprintf ("# | %18s : %s%s\n", $cat, $key, $suff);
            }
        }
    }
}


# finish populating port data without any metadata
function finish_port_nometa (&$port) {
    global $VA, $VB,
        $PERL_VERSION_A,
        $PERL_VERSION_B,
        $SPECS_DIR,
        $data_remove_version,
        $data_version_override,
        $ravensource_directory;

    $portdir = $ravensource_directory . "/"
             . bucket_directory($port["namebase"])
             . "/" . $port["namebase"];
    $cache_dir = $SPECS_DIR . "/" . $port["author"] . "/" . $port["pkgname"];

    # set version
    if (array_key_exists($port["namebase"], $data_version_override)) {
        $port["version"] = $data_version_override[$port["namebase"]];
    } else {
        $tarparts = explode("-", $port["pkgname"]);
        $numparts = count($tarparts);
        $port["version"] = $tarparts[$numparts - 1];
    }

    # Don't bother with license
    $port["license"] = "# Not provided (perl module has no META files)";

    # set descriptions
    $port["comment"]     = "No description provided";
    $port["description"] = $port["comment"] . ".";

    $port["req_comment"] = "# ------------------------------------------------------------------\n" .
                           "# |   No meta files available, therefore no dependencies defined\n" .
                           "# ------------------------------------------------------------------\n";
}


# main function to populate port data
function assemble_port_info($cpan_metaname, $force) {

    global
        $VA, $VB,
        $CPAN_INDEX,
        $SPECS_DIR;

    $ANY = "[\s\S]";
    $result = array(
        "success"     => false,
        "namebase"    => "ERROR",
        "version"     => "ERROR",
        "comment"     => "ERROR",
        "description" => "ERROR",
        "license"     => "UNSET",
        "homepage"    => "UNSET",
        "author"      => "ERROR",
        "cpandir"     => "ERROR",
        "pkgname"     => "ERROR",
        "distfile"    => "ERROR",
        "metaformat"  => "UNSET",
        "pl_builder"  => "UNSET",
        "metaname"    => $cpan_metaname,
        "justbuild"   => array($VA => array(), $VB => array()),
        "buildrun"    => array($VA => array(), $VB => array()),
        "cascade"     => array(),
        "req_comment" => "",
    );

    if (array_key_exists($cpan_metaname, $CPAN_INDEX)) {
        $payload = $CPAN_INDEX[$cpan_metaname];
    } else {
        echo ("MAJOR: '$cpan_metaname' not found in CPAN_INDEX\n");
        return $result;
    }

    # verify this is not a core module in both known perl versions
    if (is_core (true, $cpan_metaname) && is_core (false, $cpan_metaname)) {
        exit ("Remove $cpan_metaname from top ports; " .
              "it is a core module in both perl branches\n");
    }

    # scrape author and tarball out of payload
    set_namebase_author_tarball($payload,
                                $result["namebase"],
                                $result["author"],
                                $result["distfile"],
                                $result["cpandir"],
                                $result["pkgname"]);

    # Download meta files if not cached
    if (!download_metaspec($force,
                           $result["author"],
                           $result["pkgname"],
                           $result["metaformat"]))
    {
        return $result;
    }

    # set builder
    set_builder_action ($result["author"],
                        $result["pkgname"],
                        $result["pl_builder"]);

    # finish data population based on type of metafile used
    switch ($result["metaformat"]) {
        case "json":
            finish_port_json ($result);
            break;
        case "yaml":
            finish_port_yaml ($result);
            break;
        default:
            finish_port_nometa ($result);
    }

    $result["success"]     = true;
    return $result;
}

?>
