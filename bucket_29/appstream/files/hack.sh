#/bin/sh
# Nasty hack for appstreamcli bug using relative paths
echo ===  appstreamcli hack here  ===
/bin/cat "$1" | "$2" news-to-metainfo --limit=6 "$3" - > "$4"
