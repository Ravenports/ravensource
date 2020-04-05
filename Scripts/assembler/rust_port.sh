#!/bin/sh 
#
# Generate rust crate-based port given two files: 
#   crates.list
#   specification.template
#
# This script takes two argument: the port's name and its version

if [ $# -lt 2 ]; then
   echo "Usage: rust_port.sh <portname> <version>"
   exit 1
fi

CONSPIR=$(/raven/bin/ravenadm dev info D)
DPATH=$(dirname $0)
SCRIPTSDIR=$(cd ${DPATH}/.. && pwd -P)
RAVENSRC=$(dirname ${SCRIPTSDIR})

VERSION=${2}
LOCATE=$(/raven/bin/ravenadm locate $1)
FOLDER=${RAVENSRC}/bucket_${LOCATE#*bucket_}
FILE_CRATES=${FOLDER}/crates.list
FILE_SPTEMP=${FOLDER}/specification.template
TARGET=${FOLDER}/specification

for F in ${FILE_CRATES} ${FILE_SPTEMP}; do
  if [ ! -f ${F} ]; then
     echo "missing file: ${F}"
     exit 1
  fi
done

sed -e "s|%%VERSION%%|${VERSION}|" ${FILE_SPTEMP} > /tmp/spec.1

awk -f ${SCRIPTSDIR}/assembler/_rustcrate.awk ${FILE_CRATES} /tmp/spec.1 > ${TARGET}
echo "file written: ${TARGET}"

rm -f /tmp/spec.1
