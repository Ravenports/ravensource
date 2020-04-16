<?php

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
