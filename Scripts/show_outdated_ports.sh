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

CONSPIR=$(/raven/bin/ravenadm dev info D)
tmpfile=/tmp/fpc.list
ports=/usr/ports
PROG='{if ($3 != "N/A" && $3 != "generated") print}'
awk "${PROG}" ${CONSPIR}/Mk/Misc/fpc_equivalents > ${tmpfile}

while read ravenport version fpc_port; do
  if [ -f ${ports}/${fpc_port}/Makefile ]; then
    portv=$(make -C ${ports}/${fpc_port} -V PORTVERSION)
    result=$(pkg version -t "${version}" "${portv}")
    if [ $? -ne 0 ]; then
       echo "failed to query ${fpc_port}"
    fi
    if [ "${result}" = "<" ]; then
       echo "${ravenport}		version=${version} freebsd=${portv}"
    fi
  else
       echo "${ravenport}		## DOES NOT EXIST ##"
  fi
done < ${tmpfile}

rm -f ${tmpfile}
