#!/bin/sh
#
# Utility to remove ports that are no longer present in ravensource
#

rports=/usr/raven
rsource=/mech/ravensource

list=$(cd ${rports} && find bucket_* -type f)

if [ $# -lt 1 -o "${1}" != "confirm" ]; then
   echo "add 'confirm' argument to execute (this is dry run)"
   xc=1
else
   xc=0
fi


for item in ${list}; do
   if [ ! -d "${rsource}/${item}" ]; then
      echo "removing ${rsource}/$item"
      if [ $xc -eq 1 ]; then rm ${rports}/$item; fi
   fi
done
