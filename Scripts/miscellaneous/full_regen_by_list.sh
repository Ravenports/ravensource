#!/bin/sh
#
# This script requires an argument which is the base filename of a list
# file in the same directory.  E.g. "./full_regen_by_list.sh php" means
# that "php.list" is expected in the same directory.  The list file
# is the bucket_XX/namebase, one per line.
#
# The script invokes "ravenadm dev distinfo" then "ravenadm dev buildsheet"
# to regenerate the list item.

RPATH=$(realpath $0)
MISCDIR=$(dirname ${RPATH})
SCRIPTSDIR=$(dirname ${MISCDIR})
RAVENSRC=$(dirname ${SCRIPTSDIR})
myid=$(id -un)

if [ "${myid}" != "root" ]; then
   echo "Only root is allowed to regenerate ports (which requires using root-only ravenadm)"
   exit 1
fi

if [ $# -lt 1 ]; then
   echo "add the list file's basename as the first argument"
   return 1
fi

LISTFILE=${MISCDIR}/${1%.list}.list

if [ ! -f ${LISTFILE} ]; then
   echo "The file '${LISTFILE}' does not exist"
   return 1
fi

while read line; do
   (cd ${RAVENSRC}/${line} && \
   	/raven/bin/ravenadm dev distinfo &&
   	/raven/bin/ravenadm dev buildsheet . save)
done < ${LISTFILE}
