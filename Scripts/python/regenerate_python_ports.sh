#!/bin/sh
# 
# This simple script iterates thought the python list and regenerates the
# the python ports.
#

myid=$(id -un)
LOG=/tmp/python-activity.log

if [ "${myid}" != "root" ]; then
   echo "Only root is allowed to regenerate python ports (which requires using root-only ravenadm)"
   exit 1
fi

# this doesn't work; some ports have names list python-python-dateutils !
# list=$(awk -F "python-" '{print $2}' list.python)

list=$(awk '{print substr($1, 8)}' list.python)

rm -rf ${LOG}

for pypiname in ${list}; do
   ./generate_python_port.sh ${pypiname} 2>&1 | tee -a ${LOG}
done
