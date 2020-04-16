#!/bin/sh

CONSPIR=$(/raven/bin/ravenadm dev info D)
DPATH=$(dirname $0)
SCRIPTSDIR=$(cd ${DPATH} && pwd -P)

echo "If anything appears below, remove it from the top level list."
echo "It's obviously not a top-level port."
echo "You might have to replace it with grepped gem."
echo "============================================================="

while read xf; do
   G="ruby-$xf:single"
   fgrep -rn "$G" ${CONSPIR}/bucket_* 
done < ${SCRIPTSDIR}/list.top-level-gems
