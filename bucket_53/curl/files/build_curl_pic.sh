#!/bin/sh
# copy this to $WRKSRC before running
# 50+ of these objects files are empty so check before archiving.

FILE_LIST="/tmp/object_files"

noreloc="
There are no relocations in this file."

entries=$(find lib/.libs/ lib/*/.libs -type f -regextype posix-extended -regex  ".*/*[.]o")

for xf in $entries; do
    output=$(readelf --relocs $xf)
    if [ "$output" != "$noreloc" ]; then
       echo "$xf" >> "$FILE_LIST"
    fi
done

ar -crsv libcurl_pic.a `cat "$FILE_LIST"`
ranlib libcurl_pic.a
