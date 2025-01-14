<?php

# global constants
$PYTHON_CACHE = "/var/cache/python";
$PYTHON_CACHE_JSON = $PYTHON_CACHE . "/json";
$PYTHON_CACHE_ETAG = $PYTHON_CACHE . "/etag";
$PYTHON_CACHE_DIST = $PYTHON_CACHE . "/distfiles";
$PYTHONEXE = "/raven/bin/python3.12";
$EXTS    = array("tgz" => ".tar.gz",
                 "zip" => ".zip",
                 "tbz" => ".tar.bz2",
                 "wh1" => "-py3-none-any.whl",
                 "wh2" => "-py2.py3-none-any.whl");
$EXTPATS = array("tgz" => '/[.]tar[.]gz$/',
                 "zip" => '/[.]zip$/',
                 "tbz" => '/[.]tar[.]bz2$/',
                 "wh1" => '/[-]py3[-]none[-]any[.]whl$/',
                 "wh2" => '/[-]py2[.]py3[-]none[-]any[.]whl$/');

# Returns name of etag file
function etag_filename ($namebase) {
    global $PYTHON_CACHE_ETAG;

    return $PYTHON_CACHE_ETAG . "/" . $namebase . ".etag";
}


# Returns name of json file
function json_filename ($namebase) {
    global $PYTHON_CACHE_JSON;

    return $PYTHON_CACHE_JSON . "/" . $namebase . ".json";
}


# Creates cache directories as necessary
function set_up_cache () {
    global
        $PYTHON_CACHE_DIST,
        $PYTHON_CACHE_ETAG,
        $PYTHON_CACHE_JSON;

    foreach (array($PYTHON_CACHE_ETAG,
                   $PYTHON_CACHE_JSON,
                   $PYTHON_CACHE_DIST) as $dir)
    {
        if (!file_exists($dir)) {
            mkdir ($dir, 0755, true);
        }
    }
}

# Returns true if etag exists for python module
function etag_exists ($namebase) {
    $etag_file = etag_filename ($namebase);
    return file_exists($etag_file);
}


# Returns true if json exists and is not empty
function json_exists ($namebase) {
    $json_file = json_filename ($namebase);
    return file_exists($json_file) && (filesize($json_file) > 0);
}


# Returns value of previously retrieved etag
function stored_etag ($namebase) {
    $etag_file = etag_filename ($namebase);

    return file_get_contents($etag_file);
}


# Returns contents of previously stored json file
function stored_json ($namebase) {
    $json_file = json_filename ($namebase);

    return file_get_contents($json_file);
}

# Writes (or overwrites) etag value to cache
function write_etag ($namebase, $etag) {
    $etag_file = etag_filename ($namebase);

    file_put_contents($etag_file, $etag);
}


# Writes (or overwrites) json file to cache
function write_json ($namebase, $json) {
    $json_file = json_filename ($namebase);

    file_put_contents($json_file, $json);
}


# Deletes etag file from cache
function delete_stored_etag ($namebase) {
    if (etag_exists($namebase)) {
        $etag_file = etag_filename ($namebase);
        unlink ($etag_file);
    }
}


# Searches the HTTP response header for Etag and returns the contents
# If not found, returns False
# example: [11] => ETag: "FqVhlhRsztlMsjS4Vwiayg"
function extract_etag ($response_header) {
    foreach ($response_header as $line) {
        if (strtolower(substr($line, 0, 5)) == "etag:") {
            $parts = explode(" ", $line);
            $inner = explode('"', $parts[1]);
            return $inner[1];
        }
    }
    return false;
}


# Searches the HTTP response header and returns True if 304 (not modified)
# response has been returned.
function use_cached_json ($response_header) {
    return (strstr($response_header[0], "304 Not Modified") !== False);
}


# Searches the HTTP response header and returns True if 301 (moved)
# response has been returned.
function moved_permanently ($response_header) {
    return (strstr($response_header[0], "301 Moved Permanently") !== False);
}


# Searches the HTTP response header for the redirection address
function new_location ($response_header) {
    foreach ($response_header as $line) {
        if (substr($line, 0, 9) == "Location:") {
            return substr($line, 10);
        }
    }
    return "Location not found";
}


# Check for existing distfile and check md5
# Return true if file exists and meets checksum
function tarball_in_place ($tarball, $md5sum) {
    global $PYTHON_CACHE_DIST;

    $fileloc = $PYTHON_CACHE_DIST . "/" . $tarball;
    if (file_exists($fileloc)) {
        $file_md5 = md5_file($fileloc);
        return ($file_md5 == $md5sum);
    }
    return false;
}


function download_tarball ($tarball, $fetch_url) {
   global $PYTHON_CACHE_DIST;

   $outfile  = $PYTHON_CACHE_DIST . "/" . $tarball;
   $upstream = $fetch_url;

   if(file_put_contents($outfile, file_get_contents($upstream))) {
       printf ("%-62s : %s\n", "", "Retrieved distfile");
       return true;
   } else {
       echo "Failed to download $tarball\n";
       return false;
   }
}


# converts x, x.y, x.y.z into numeric value for comparison
function convert_into_version ($raw) {
    $result = 0;
    $parts = explode (".", trim($raw));
    switch (count($parts)) {
        case 1:
           $result = (int)$parts[0] * 1000000;
           break;
        case 2:
           $result = (int)$parts[0] * 1000000 +
                     (int)$parts[1] *    1000;
        default:
           $result = (int)$parts[0] * 1000000 +
                     (int)$parts[1] *    1000 +
                     (int)$parts[2];
    }
    return $result;
}


# formats minimum python
function sanitize_min_python ($requires_python) {
    $result = is_null($requires_python) ?
             "none" :
             (empty($requires_python) ?
                 "none" :
                 $requires_python);
    return $result;
}


# Get the latest json file.
# The PyPi site supports etags, so cache previous results.
# If the PyPi server says the content is unmodified, return our cached file,
# otherwise cache what we fetch and return it.
function fetch_from_pypi ($namebase) {
    global $PYTHON_CACHE_JSON;

    $pypi_url = "https://pypi.org/pypi/" . $namebase . "/json";

    printf ("%-62s : ", "Downloading $namebase");
    if (etag_exists($namebase)) {
        $etag = stored_etag ($namebase);
        $http_scheme = array
            ("method" => "GET",
             "header" => "User-Agent: Ravenports Python Generator\r\n" .
                         "Accept: application/json\r\n" .
                         "If-None-Match: \"$etag\"\r\n");
        $opts = array ("http" => $http_scheme);
        $context = stream_context_create ($opts);
        $json = file_get_contents($pypi_url, false, $context);
        if ($json === False) {
           echo "FAILED! (with etag)\n";
           return false;
        }
        if (use_cached_json ($http_response_header)) {
            echo "Cached\n";
            return stored_json($namebase);
        } else {
            # check for valid namebase
            if (moved_permanently ($http_response_header)) {
                exit ("\nFATAL: $namebase permanent moved to " .
                      new_location ($http_response_header) . "\n");
            }
            $new_etag = extract_etag($http_response_header);
            if ($new_etag !== false) {
                write_etag ($namebase, $new_etag);
            }
            write_json ($namebase, $json);
            echo "Successful (new content)\n";
            return $json;
        }
    }

    # No cache available, pull it unconditionally
    $json = file_get_contents($pypi_url);
    if ($json === False) {
        echo "FAILED!\n";
        return false;
    }
    $new_etag = extract_etag($http_response_header);
    write_etag ($namebase, $new_etag);
    write_json ($namebase, $json);
    echo "Successful (cache empty)\n";
    return $json;
}


# Many setup.py files are busted.  This script fixes the known issues.
function inline_fix_setup ($namebase, $src) {
   $known_issues = array (
       "lxml"         => '/Building lxml/d',
       "intervaltree" => '/print("Version/d; s/print("!!!.*/    pass/',
       "borgbackup"   => '/Detected/d',
       "compreffor"   => '/print/d',
       "libversion"   => '/[*][*]pkgconfig/d',
       "cffi"         => '/__main__/ s|^.*$|if True:|',
       "pycryptodomex"=> '/set_compiler_options/d',
       "aiohttp"      => '/print(/d',
       "xml2rfc"      => false,
       "psautohint"   => false,
       "netbox-network-importer" => '/pyats\[full\]/d',
       "pyzmq"        => '/cythonize(/ s|, |, quiet=True, |; /packaging.version/d; s|if V(.*$|if False:|',
       "cffsubr"      => 's|"Linux"|platform.system()|',
       "msgpack"      => false,
       "python-netbox" => '/install_requires=/ s|.ipaddress., ||',
       "netdoc"        => '/install_requires=/ s|.ipaddress., ||',
       "pycryptodome"  => false,
       "freetype-py"   => '/system-provided FreeType/d',
       "json2html"     => '/classifiers/d; /  ),/d',
   );
   $setup = $src . "/setup.py";
   if (array_key_exists($namebase, $known_issues)) {
       $sedcmd = $known_issues[$namebase];
       if ($sedcmd !== false) {
           shell_exec("sed -i.bak -e '$sedcmd' $setup");
       }
       # additional changes
       switch ($namebase) {
           case "lxml":
               $xf = $src . "/setupinfo.py";
               shell_exec("sed -i.bak -E -e '/Building without/d; /Using build/ s/^.*$$/        pass/; /lib_versions[[]?[1]?[]]?)/d; s/if _library_dirs:/if 0:/; s/not check_build_dependencies..:/0:/' $xf");
               break;
           case "pycryptodome":
               $xf = $src . "/compiler_opt.py";
               shell_exec ("sed -i.bak -e \"s|print(.*|pass|\" $xf");
               break;
           case "cffi":
           case "xml2rfc":
           case "msgpack":
           case "aiohttp":
           case "psautohint":
           case "freetype-py":
               $xf = $src . "/pyproject.toml";
               $filehandle = fopen($xf, "a");
               fwrite ($filehandle, "[tool.setuptools_scm]\n");
               fclose ($filehandle);
               break;
       }
   }

   # fix __main__ issues
   # convert "from distutils.core" to "from setuptools"
   $setcontents = file_get_contents($setup);
   if (strstr($setcontents, "from distutils.core import setup")) {
       file_put_contents($setup . ".bak2", $setcontents);
       $setcontents = str_replace("from distutils.core import setup",
                                  "from setuptools import setup", $setcontents);
       file_put_contents($setup, $setcontents);
   }

   $magic = "if __name__ == '__main__'";
   if (strstr($setcontents, "\n$magic")) {
       file_put_contents($setup . ".bak3", $setcontents);
       $lines = file($setup);
       $newcontents = "";
       $len = strlen($magic);
       $active = false;
       foreach ($lines as $line) {
           if (substr($line, 0, $len) == $magic) {
               $active = true;
           } elseif ($active) {
              if (substr($line, 0, 4) == "    ") {
                  $newcontents .= substr($line, 4);
              } elseif (substr($line, 0, 1) == "\t") {
                  $newcontents .= substr($line, 1);
              } else {
                  $active = false;
                  $newcontents .= $line;
              }
           } else {
               $newcontents .= $line;
           }
       }
       file_put_contents($setup, $newcontents);
   }
}


# Line contains requires-dists
function only_dists($var) {
   return (substr($var, 0, 14) == "Requires-Dist:");
}


# Line doesn't contain "extras" or platform_system == "Windows" or "win32"
# or sys_platform == "linux"  (ignore all system-specific dependencies)
function skip_extras($var) {
   if (strpos($var, "enum-compat") !== false) {
      return false;
   }
   if (strpos($var, '"Windows"') !== false) {
      return false;
   }
   if (strpos($var, "'Windows'") !== false) {
      return false;
   }
   if (strpos($var, '"win32"') !== false) {
      return false;
   }
   if (strpos($var, "'win32'") !== false) {
      return false;
   }
   if (strpos($var, 'sys_platform ==') !== false) {
      return false;
   }
   if (str_starts_with($var, "Requires-Dist: meson")) {
      return false;
   }
   $pos = strpos($var, "extra ==");
   return ($pos === false);
}


# prevent circular dependency on Sphinx
function remove_sphinx($var) {
    $pos = strpos($var, "Sphinx>=");
    return ($pos === false);
}


# Line doesn't contain implementation_name == pypy
function skip_bad_SU_requirements($var) {
   if (preg_match('/implementation_name == ["\']pypy["\']/', $var) > 0) {
      return false;
   }
   return true;
}

# Obtain runtime dependencies from wheel file
function scan_wheel_for_rundeps ($metafile) {
    $contents = file_get_contents ($metafile);
    $intermediate = array_filter(explode("\n", $contents), "only_dists");
    return (array_map("trim", $intermediate));
}


# Determine run depends per python version
function get_run_depends ($base_dependencies, $pversion) {
    global $data_corrections;

    $result = array();
    foreach ($base_dependencies as $line) {
        $pos = strpos($line, "python_version");
        if ($pos === false) {
             # No limiting version information; all versions need it
             $required = true;
        } else {
             # example, worst case 2 python_version checks
             # dataclasses (>=0.8,<0.9); python_version >= "3.6" and python_version < "3.7"
             $sc = strpos($line, ";");
             $clause = substr($line, $sc + 1);
             $xformed = str_replace(array ("python_version",
                                           'implementation_name == "cpython"',
                                           'platform_python_implementation=="CPython"',
                                           '"', "'", ".", "and"),
                                    array ("\$pversion", "1", "1", "", "", "", "&&"),
                                    $clause);
             $teststr = "\$required = " . $xformed . ";";
             eval($teststr);
        }
        if ($required) {
            $req = trim(preg_replace('/^Requires-Dist: ([^ <>=~!\[;]+)(.*)$/', '\1', $line));
            # ansible doesn't follow normal python naming rules, must be added manually
            # importlib is obsolete due to being included in modern python
            if (in_array($req, array("ansible", "importlib"))) {
               continue;
            }
            if (array_key_exists ($req, $data_corrections)) {
                $req = $data_corrections[$req];
            }
            if (!in_array("python-" . $req, $result)) {
                array_push($result, "python-" . $req);
            }
        }
    }
    return $result;
}


# Setup.py handler #1
function program_unittest() {
    $code = <<<'EOF'
import unittest.mock
import setuptools

with unittest.mock.patch.object(setuptools, 'setup') as mock_setup:
    import setup

if mock_setup.call_args is not None:
    args, kwargs = mock_setup.call_args
    print ('\n'.join(kwargs.get('install_requires', [])))
    print ('\n'.join(kwargs.get('setup_requires', [])))
EOF;
    return $code;
}


# Setup.py handler #2
function program_distutils() {
    $code = <<<'EOF'
import distutils.core
import distutils.log
import warnings
distutils.log.set_threshold(distutils.log.ERROR)
warnings.filterwarnings('ignore')
setup = distutils.core.run_setup("setup.py")
if hasattr (setup, 'install_requires'):
    print ('\n'.join(setup.install_requires))
if hasattr (setup, 'setup_requires'):
    print ('\n'.join(setup.setup_requires))
EOF;
    return $code;
}


# pyproject.toml handler
function program_toml($file) {
    $code = <<<EOF
import toml
from packaging.requirements import InvalidRequirement, Requirement

reqs = {}
deps = {}
parsed_deps = []
def filter_out(bdep):
   if bdep in ["wheel", "setuptools", "build", "installer", "pip"]:
      return True
   if bdep[:11] in ["setuptools;", "setuptools<", "setuptools=", "setuptools>"]:
      return True
   return False

proj = toml.load(open("$file"))
if "build-system" in proj:
   if "requires" in proj["build-system"]:
      reqs = proj["build-system"]["requires"]
if "project" in proj:
   if "dependencies" in proj["project"]:
      deps = proj["project"]["dependencies"]

for item in reqs:
    try:
        # only accept valid dependencies and those that do not depend on a url (i.e.: from pypi)
        # pep517 pulls in sutool, pip, wheel, build and installer so filter those out
        req = Requirement(item)
        if req.url is None:
            if not filter_out(item):
               parsed_deps.append("build: " + item)
    except:
        pass
for item in deps:
    try:
        # only accept valid dependencies and those that do not depend on a url (i.e.: from pypi)
        req = Requirement(item)
        if req.url is None:
            parsed_deps.append("buildrun: " + item)
    except:
        pass
print("\\n".join(parsed_deps))
EOF;
    return $code;
}


# Establish buildruns (only using latest python)
function set_buildrun (&$portdata, $PDUO) {
    global
        $data_corrections,
        $EXTS,
        $EXTPATS,
        $PYTHONEXE,
        $PYTHON_CACHE_DIST;

    $WORKZONE = "/tmp/expand";

    # make sure work area is clear
    shell_exec("rm -rf $WORKZONE");
    mkdir ($WORKZONE, 0755, true);

    # explode distfile in work area
    $tarball = $PYTHON_CACHE_DIST . "/" . $portdata["distfile"];
    if (!file_exists($tarball)) {
       echo "ERROR: $tarball does not exist (set_buildrun)\n";
       return;
    }
    shell_exec("cd $WORKZONE && tar -xf $tarball");
    foreach ($EXTS as $key => $ext) {
        $distname = preg_replace ($EXTPATS[$key], "", $portdata["distfile"]);
        if ($distname != $portdata["distfile"]) {
           break;
        }
    }
    if ($portdata["wheel_dist"]) {
       # Correct any misnamed distfiles
       if (substr($distname, 0, 6) == "eyeD3-") {
          $distname = "eyed3-" . substr($distname, 6);
       }
       else if (substr($distname, 0, 23) == "sphinxcontrib.applehelp") {
          $distname = str_replace("b.a", "b_a", $distname);
       }
       else if (substr($distname, 0, 4) == "N2G-") {
          $distname = "n2g-" . substr($distname, 4);
       }
       $src = $WORKZONE . "/" . $distname . ".dist-info";
       $metadata = $src . "/METADATA";
       if (!file_exists($metadata)) {
          echo "ERROR: $metadata does not exist (set_buildrun)\n";
          return;
       }
       $req_lines = scan_wheel_for_rundeps($metadata);
       $base_reqs = array_filter($req_lines, "skip_extras");
       if (
         (substr($distname, 0, 22) == "sphinxcontrib_htmlhelp") ||
         (substr($distname, 0, 21) == "sphinxcontrib_devhelp") ||
         (substr($distname, 0, 20) == "sphinxcontrib_qthelp") ||
         (substr($distname, 0, 23) == "sphinxcontrib_applehelp") ||
         (substr($distname, 0, 29) == "sphinxcontrib_serializinghtml")
       ) {
          $base_reqs = array_filter($base_reqs, "remove_sphinx");
       }
       $comment_reqs = preg_replace('/^Requires-Dist: /', '# ', $req_lines);
       $portdata["req_comment"] .= join("\n", $comment_reqs);
       foreach ($PDUO as $V) {
           $portdata["justrun_" . $V["variant"]] = get_run_depends ($base_reqs, $V["version"]);
       }
       return;
    }

    # This is a setuptools "sdist" port (expected pyproject.toml or setup.py)
    $src = $WORKZONE . "/" . $distname;
    $mockfile = $src . "/obtain-req.py";
    $toml = $src . "/pyproject.toml";
    if (file_exists($toml)) {
       $program = program_toml($toml);
       $portdata["toml_dist"] = true;
       $portdata["req_comment"] = "# Requires-Dist extracted from pyproject.toml file\n";
    }
    else {
       $setup = $src . "/setup.py";
       if (!file_exists($setup)) {
          echo "ERROR: $setup does not exist (set_buildrun)\n";
           return;
       }
       inline_fix_setup ($portdata["name"], $src);
       switch ($portdata["name"]) {
          case "PyYAML":
          case "Twisted":
          case "attrs":
          case "fonttools":
          case "netaddr":
          case "pylint":
          case "pytest-runner":
          case "reportlab":
          case "setuptools-scm":
          case "skia-pathops":
          case "mutagen":
          case "protobuf":
          case "compreffor":
          case "zipp":		// above -- not distutils script
          case "PyNaCl":		// above -- tries downloading
          case "kombu":		// setup.cfg misconfig
          case "bcrypt":		// c errors
             $program = program_unittest();
             break;
          default:
            $program = program_distutils();
            break;
       }
    }
    file_put_contents($mockfile, $program);
    $requirements = shell_exec ("cd $src && $PYTHONEXE obtain-req.py");
    if ($requirements === null) {
       $clean_reqs = array();
    } else {
       $clean_reqs = array_filter(explode("\n", $requirements));
       $clean_reqs = array_filter($clean_reqs, "skip_bad_SU_requirements");
    }
    $comment_reqs = preg_replace('/^/', '# ', $clean_reqs);
    $clean_reqs = preg_replace('/ /', '', $clean_reqs);
    $clean_reqs2 = array();
    $lowversion = $PDUO["VA"]["version"];
    foreach ($clean_reqs as $req) {
        if (strpos($req, "python_version") == false) {
            array_push($clean_reqs2, $req);
        } else {
            // example: typing_extensions;python_version<="3.7"
            $sc = strpos($req, ";");
            $clause = substr($req, $sc + 1);
            $xformed = str_replace(array ("python_version", '"', "'", ".", "and"),
                                   array ("\$lowversion", "", "", "", "&&"),
                                   $clause);
            $teststr = "\$required = " . $xformed . ";";
            try {
               eval($teststr . "\n");
            } catch (Throwable $t) {
               $required = false;
               echo("failed eval of $req");
            }
            if ($required) {
               array_push($clean_reqs2, substr($req, 0, $sc));
            }
        }
    }

    $portdata["req_comment"] .= join("\n", $comment_reqs);
    $stripped_reqs = preg_replace('/(.*)([><!=~;].*)$/U', '\1', $clean_reqs2);
    foreach ($stripped_reqs as $req) {
        if ($portdata["toml_dist"]) {
            $buildonly = (substr ($req, 0, 6) == "build:");
            $req = trim(substr($req, $buildonly ? 6 : 9));
            if (array_key_exists ($req, $data_corrections)) {
                $req = $data_corrections[$req];
            }
            $pyreq = "python-" . $req;
            if ($buildonly) {
                if (!in_array($pyreq, $portdata["build"])) {
                    array_push($portdata["build"], $pyreq);
                }
            }
            else {
               if (!in_array($pyreq, $portdata["buildrun"])) {
                   array_push($portdata["buildrun"], $pyreq);
               }
            }
        }
        else {
            $req = trim($req);
            if (array_key_exists ($req, $data_corrections)) {
                $req = $data_corrections[$req];
            }

            if (!in_array("python-" . $req, $portdata["buildrun"])) {
                array_push($portdata["buildrun"], "python-" . $req);
            }
        }
    }
}


# Returns true if the $fragment is the last part of $main_string
function trails($main_string, $fragment) {
   $flen = strlen($fragment);
   $mlen = strlen($main_string);
   if ($flen > $mlen) {
      return false;
   }
   $start_index = $mlen - $flen;
   return (substr($main_string, $start_index) == $fragment);
}


# main function to ready python module and extract usable information
function scrape_python_info ($namebase, $force, $PDUO) {
    $result = array(
        "success"     => false,
        "name"        => $namebase,
        "version"     => "ERROR",
        "comment"     => "ERROR",
        "description" => "ERROR",
        "license"     => "UNSET",
        "homepage"    => "UNSET",
        "distfile"    => "ERROR",
        "md5sum"      => "ERROR",
        "fetch_url"   => "ERROR",
        "min_python"  => "UNSET",
        "pypi_uri"    => "UNSET",
        "wheel_dist"  => false,
        "toml_dist"   => false,
        "build"       => array(),
        "buildrun"    => array(),
        "justrun_" . $PDUO["VA"]["variant"] => array(),
        "justrun_" . $PDUO["VB"]["variant"] => array(),
        "req_comment" => "# install_requires extracted from setup.py\n",
    );

    if ($force || !json_exists ($namebase)) {
        delete_stored_etag ($namebase);
    }
    if (fetch_from_pypi ($namebase) !== False) {
         $module_json = stored_json ($namebase);
         $obj = json_decode($module_json, false, 512, JSON_INVALID_UTF8_IGNORE);
         if (is_null ($obj)) {
             return $result;
         }
         $version = $obj->info->version;
         if (!is_array ($obj->releases->$version)) {
             return $result;
         }
         if ($obj->info->home_page == "") {
            if (property_exists($obj->info, "project_urls")) {
               if ($obj->info->project_urls !== null) {
                  if (property_exists($obj->info->project_urls, "Homepage")) {
                     $obj->info->home_page = $obj->info->project_urls->Homepage;
                  } else if (property_exists($obj->info->project_urls, "homepage")) {
                     $obj->info->home_page = $obj->info->project_urls->homepage;
                  } else if (property_exists($obj->info->project_urls, "Source")) {
                     $obj->info->home_page = $obj->info->project_urls->Source;
                  }
               }
            }
         }
         if ($obj->info->home_page == "") {
            if (property_exists($obj->info, "project_url")) {
               if ($obj->info->project_urls != "") {
                  $obj->info->home_page = $obj->info->project_url;
               }
            }
         }
         $result["version"]     = $version;
         $result["comment"]     = $obj->info->summary;
         $result["description"] = $obj->info->description;
         $result["license"]     = $obj->info->license;
         $result["homepage"]    = $obj->info->home_page;
         $result["pypi_uri"]	= substr($namebase, 0, 1) . "/" . $namebase;

         # handle really long licenses
         if ($obj->info->license !== null && (strlen($obj->info->license) > 77)) {
            $temp = wordwrap ($obj->info->license, 70);
            $lines = explode("\n", $temp);
            $lines = array_map('trim', $lines);    # remove extreme whitespace
            $lines = array_filter($lines);         # remove blank lines
            $result["license"] = join("\n# ", $lines);
         }

         $release_found = false;
         foreach ($obj->releases->$version as $entry) {
             # we can use wheel files if they are generic
             if ($entry->packagetype == "bdist_wheel" &&
                 !in_array($namebase, array("pip","sphinxcontrib-adadomain")) &&
                 trails($entry->filename, "py3-none-any.whl")
             ) {
                 $release_found = true;
                 $result["wheel_dist"] = true;
                 $result["md5sum"]   = $entry->md5_digest;
                 $result["distfile"] = $entry->filename;
                 $result["fetch_url"] = $entry->url;
                 $result["min_python"] = sanitize_min_python
                                           ($entry->requires_python);
                 $result["req_comment"] = "# Requires-Dist extracted from wheel metadata\n";
                 break;
             }
         }
         if (!$release_found) {
           foreach ($obj->releases->$version as $entry) {
             if ($entry->packagetype == "sdist") {
                 $release_found = true;
                 $result["md5sum"]   = $entry->md5_digest;
                 $result["distfile"] = $entry->filename;
                 $result["fetch_url"] = $entry->url;
                 $result["min_python"] = sanitize_min_python
                                           ($entry->requires_python);
                 break;
             }
           }
         }
         if (!$release_found) {
             # There's a bad "version" number.  Search releases
             # and take the highest available, then redefine "version"
             # if none found, return with an error
             $highest_version = 0;
             $highest_key = "";
             $highest_distfile = "";
             $highest_md5sum = "";
             $highest_minpy = "";
             $highest_url = "";

             foreach ($obj->releases as $rv => $version_obj) {
                foreach ($version_obj as $entry) {
                    if ($entry->packagetype == "sdist") {
                       $thisver = convert_into_version ($rv);
                       if ($thisver > $highest_version) {
                           $highest_version = $thisver;
                           $highest_key = $rv;
                           $highest_distfile = $entry->filename;
                           $highest_url      = $entry->url;
                           $highest_md5sum   = $entry->md5_digest;
                           $highest_minpy    = sanitize_min_python
                                                 ($entry->requires_python);
                       }
                    }
                }
             }
             if ($highest_version > 0) {
                 $result["version"]  = $highest_key;
                 $result["md5sum"]   = $highest_md5sum;
                 $result["distfile"] = $highest_distfile;
                 $result["min_python"] = $highest_minpy;
                 $result["fetch_url"]  = $highest_url;
             } else {
                 return $result;
             }
         }

         if (!tarball_in_place ($result["distfile"], $result["md5sum"])) {
             if (download_tarball ($result["distfile"], $result["fetch_url"])) {
                 if (!tarball_in_place ($result["distfile"], $result["md5sum"])) {
                    # failed to verify md5sum
                    echo "Failed to verify md5 checksum of " . $result["distfile"] . "\n";
                    return $result;
                 }
             } else {
                 # failed to download tarball
                 return $result;
             }
         }
         set_buildrun($result, $PDUO);
         $result["success"] = true;
    }

    return $result;
}
?>
