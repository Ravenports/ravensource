#!/bin/sh

pathtoexec=$(realpath $0)
thisdir=$(dirname ${pathtoexec})
wrkdir=/tmp/rubygems
archurl=http://rubygems.org/latest_specs.4.8.gz

rm -rf ${wrkdir}
mkdir -p ${wrkdir}
fetch ${archurl} -o ${wrkdir}

if [ $? -ne 0 ]; then
  echo "download failed"
  exit 1;
fi

ruby24 ${thisdir}/dump_latest.rb | awk '{\
tracker++;\
if (tracker == 1) { software = $1 }; \
if (tracker == 2) { version = $1 };\
if (tracker == 3) { print software " " version; tracker = 0 };\
}' > ${wrkdir}/gem_index

