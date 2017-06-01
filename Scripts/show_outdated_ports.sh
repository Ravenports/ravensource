#!/bin/sh
#
# Before running this script, update freebsd ports (/usr/ports) and
# regenerate index with "ravenadm dev generate-index" command.  Before
# that, regenerate conspiracy directory if necessary.  This provides
# the latest data for the script to function properly.
#
# The purpose of the script is to show which Ravenports are behind
# their FreeBSD Ports Collection counterparts.  It only applies to
# non-generated ports that have counterparts at FreeBSD.
#

location=/usr/raven
tmpfile=/tmp/fpc.list
ports=/usr/ports
PROG='{if ($3 != "N/A" && $3 != "generated") print}'
awk "${PROG}" ${location}/Mk/Misc/fpc_equivalents > ${tmpfile}

while read ravenport version fpc_port; do
  portv=$(make -C ${ports}/${fpc_port} -V PORTVERSION)
  result=$(pkg version -t ${version} ${portv})
  if [ "${result}" = "<" ]; then
     echo "${ravenport}		version=${version} freebsd=${portv}"
  fi
done < ${tmpfile}

rm -f ${tmpfile}



