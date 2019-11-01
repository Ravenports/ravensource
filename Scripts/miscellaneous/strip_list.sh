#!/bin/sh
#
# This script requires an argument which is the base filename of a list
# file in the same directory.  E.g. "./strip;_list.sh php" means
# that "php.list" is expected in the same directory.  The list file
# is the bucket_XX/namebase, one per line.
#
# This script strips "bucket_XX/" and outputs the rest which can be used
# as a build list for ravenadm.

DPATH=$(dirname $0)
MISCDIR=$(cd ${DPATH} && pwd -P)
LISTFILE=${MISCDIR}/${1%.list}.list

if [ ! -f ${LISTFILE} ]; then
   echo "The file '${LISTFILE}' does not exist"
   return 1
fi

awk -F/ '{print $2}' ${LISTFILE}
