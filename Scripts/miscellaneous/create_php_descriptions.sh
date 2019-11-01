#!/bin/sh
#
# This script requires an argument which is the base filename of a list
# file in the same directory.  E.g. "./full_regen_by_list.sh php" means
# that "php.list" is expected in the same directory.  The list file
# is the bucket_XX/namebase, one per line.
#
# This script creates descriptions/desc.single in each given port

DPATH=$(dirname $0)
MISCDIR=$(cd ${DPATH} && pwd -P)
SCRIPTSDIR=$(dirname ${MISCDIR})
RAVENSRC=$(dirname ${SCRIPTSDIR})
myid=$(id -un)

if [ $# -lt 1 ]; then
   echo "add the list file's basename as the first argument"
   return 1
fi

if [ $# -lt 2 -o "${2}" != "confirm" ]; then
   echo "add 'confirm' to second argument to activate script"
   return 1
fi

VER=${1%.list}
PHP=${VER#php}
LISTFILE=${MISCDIR}/${VER}.list

if [ ! -f ${LISTFILE} ]; then
   echo "The file '${LISTFILE}' does not exist"
   return 1
fi

while read line; do
   if [ "${line#bucket_??\/}" != "${VER}" ]; then
      mkdir -p ${RAVENSRC}/${line}/descriptions
      echo "This package contains the ${line#bucket_??\/php??-} extension for PHP ${PHP%?}.${PHP#?}." \
      	> ${RAVENSRC}/${line}/descriptions/desc.single
   fi
done < ${LISTFILE}
