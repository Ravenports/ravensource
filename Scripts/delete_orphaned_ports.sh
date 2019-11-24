#!/bin/sh
#
# Utility to remove ports that are no longer present in ravensource
#

DPATH=$(dirname $0)
SCRIPTSDIR=$(cd ${DPATH} && pwd -P)
RAVENSRC=$(dirname ${SCRIPTSDIR})
CONSPIR=$(/raven/bin/ravenadm dev info D)

list=$(cd ${CONSPIR} && find bucket_* -type f)

if [ $# -lt 1 -o "${1}" != "confirm" ]; then
   echo "add 'confirm' argument to execute (this is dry run)"
   xc=0
else
   xc=1
fi


for item in ${list}; do
   if [ ! -d "${RAVENSRC}/${item}" ]; then
      echo "removing ${RAVENSRC}/$item"
      if [ $xc -eq 1 ]; then rm ${CONSPIR}/$item; fi
   fi
done
