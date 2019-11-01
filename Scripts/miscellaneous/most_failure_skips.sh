#!/bin/sh

profile=$(/raven/bin/ravenadm dev info G)
logsdir=${profile}/logs/logs
fail_log=${logsdir}/02_failure_list.log

if [ ! -f ${fail_log} ]; then
   echo "log file is missing, aborting..."
   echo "(${fail_log})"
   exit 1
fi

awk '{print $4 " " $2}' ${fail_log} | sort -nr

