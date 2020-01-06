#!/bin/sh

RUBYEXE=/raven/bin/ruby27
pathtoexec=$(realpath $0)
thisdir=$(dirname ${pathtoexec})
wrkdir=/tmp/rubygems
archurl=http://rubygems.org/latest_specs.4.8.gz

rm -rf ${wrkdir}
mkdir -p ${wrkdir}
fetch --no-verify-peer ${archurl} -o ${wrkdir}

if [ $? -ne 0 ]; then
  echo "download failed"
  exit 1;
fi

$RUBYEXE ${thisdir}/dump_latest.rb | awk '{\
tracker++;\
if (tracker == 1) { software = $1 }; \
if (tracker == 2) { version = $1 };\
if (tracker == 3) { print software " " version; tracker = 0 };\
}' > ${wrkdir}/gem_index.raw

sort -u ${wrkdir}/gem_index.raw > ${wrkdir}/gem_index.sorted

awk '{\
if (NR==1) { last_line=$0; last_one=$1; next };\
if ($1 != last_one)\
 { print last_line };\
last_line=$0;\
last_one = $1;\
}\
END { print last_line; }' \
${wrkdir}/gem_index.sorted > ${wrkdir}/gem_index

rm ${wrkdir}/gem_index.raw
rm ${wrkdir}/gem_index.sorted
