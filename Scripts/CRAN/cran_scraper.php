<?php

# returns boolean - true if given module is part of R base
function core_module ($module) {
   $coremods = array (
       "R", "KernSmooth", "MASS", "Matrix", "base", "boot", "class",
       "cluster", "codetools", "compiler", "datasets", "foreign",
       "grDevices", "graphics", "grid", "lattice", "methods", "mgcv",
       "nlme", "nnet", "parallel", "rpart", "spatial", "splines",
       "stats", "stats4", "survival", "tcltk", "tools", "utils"
    );
    return in_array($module, $coremods);
}

# performs strip_tags, followed by decoding html special chars,
# followed by converting additional html, followed by trim
function strip_all ($raw_text) {
    $result = strip_tags ($raw_text);
    $result = htmlspecialchars_decode ($result);
    $result = str_replace("&ge;", ">=", $result);
    return trim($result);
}

# If $raw_text contains any spaces, only the text up the the first
# space is returned, otherwise the entire string is returned.
# (assumes $raw_text is already trimmed)
# (carriage returns converted to spaces first)
function first_word ($raw_text) {
   $remove_character = array("\n", "\r\n", "\r");
   $nocr = str_replace($remove_character , " ", $raw_text);
   $arr = explode(" ", $nocr);
   return $arr[0];
}

function process_buildrun ($matched_text, &$storage) {
    $pass_1 = preg_replace (array("/[(][\s\S]*[)]/U"), array(""), $matched_text);
    $pass_2 = strip_all ($pass_1);
    if ($pass_2 != "") {
        $pass_3 = explode (",", $pass_2);
        foreach ($pass_3 as $part) {
           $dependency = trim($part);
           if (!core_module($dependency) &&
               !in_array($dependency, $storage))
           {
              array_push($storage, $dependency);
           }
        }
    }
}

# Fetches the cran webpage return extracted information
function scrape_cran_page ($namebase) {
    $url = "https://cran.r-project.org/web/packages/$namebase/index.html";
    $ANY = "[\s\S]";
    $SCELL = "<td>(.*)<\/td>";
    $ACELL = "<td>($ANY*)<\/td>";

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

    $webpage = file_get_contents($url);
    if ($webpage === false) {
        return $result;
    }
    if (preg_match("/<h2>.*: ($ANY*)<\/h2>$ANY?<p>($ANY*)<\/p>/U", $webpage, $matches) == 1) {
        $result["comment"] = str_replace("\n", "", trim($matches[1]));
        $result["description"] = trim($matches[2]);
    }

    if (preg_match("/<td>Version:<\/td>$ANY?$SCELL/U", $webpage, $matches) == 1) {
        $result["version"] = trim($matches[1]);
    }

    if (preg_match("/<td>License:<\/td>$ANY?$SCELL/U", $webpage, $matches) == 1) {
        $result["license"] = strip_all($matches[1]);
    }

    if (preg_match("/<td>URL:<\/td>$ANY?$ACELL/U", $webpage, $matches) == 1) {
        $result["homepage"] = first_word (strip_all($matches[1]));
    }

    if (preg_match("/<td>\s*Package&nbsp;source:\s*<\/td>$ANY?$SCELL/U", $webpage, $matches) == 1) {
        $result["distfile"] = strip_all($matches[1]);
    }

    if (preg_match("/<td>Depends:<\/td>$ANY?$ACELL/U", $webpage, $matches) == 1) {
        process_buildrun ($matches[1], $result["buildrun"]);
    }

    if (preg_match("/<td>Imports:<\/td>$ANY?$ACELL/U", $webpage, $matches) == 1) {
        process_buildrun ($matches[1], $result["buildrun"]);
    }
    if (preg_match("/<td>LinkingTo:<\/td>$ANY?$ACELL/U", $webpage, $matches) == 1) {
        process_buildrun ($matches[1], $result["buildrun"]);
    }
    $result["success"] = true;

    return $result;
}

?>
