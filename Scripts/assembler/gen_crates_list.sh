#!/bin/sh 
#
# Generate crates.list for a rust port
#
# This script takes two argument: the port's name and the path to
# the Cargo.lock file

if [ $# -lt 2 ]; then
   echo "Usage: gen_crates_list.sh <portname> <path-to-lock-file>"
   exit 1
fi

CONSPIR=$(/raven/bin/ravenadm dev info D)
DPATH=$(dirname $0)
SCRIPTSDIR=$(cd ${DPATH}/.. && pwd -P)
RAVENSRC=$(dirname ${SCRIPTSDIR})

LOCK_FILE=${2}
LOCATE=$(/raven/bin/ravenadm locate $1)
FOLDER=${RAVENSRC}/bucket_${LOCATE#*bucket_}
FILE_CRATES=${FOLDER}/crates.list

if [ ! -f ${LOCK_FILE} ]; then
   echo "missing file: ${LOCK_FILE}"
   exit 1
fi

awk -f ${SCRIPTSDIR}/assembler/_lock.awk -vtarget=$1 ${LOCK_FILE} > ${FILE_CRATES}
echo "file written: ${FILE_CRATES}"
