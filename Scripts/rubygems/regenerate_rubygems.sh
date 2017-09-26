#!/bin/sh
#
# This script regenerates all listed rubygem ports
#
# script: ./dump_latest.sh
#
#   This creates /tmp/rubygems/gem_index, which comes from data transformed
#   from the latest rubygem versions spec file
#
# script: ./single_rubygem.sh
#
#   This script actually generates the rubygem port given the rubygem name.
#
# file: ./top_ports.list
#
#   This is a list of rubygem ports that we want.  They are considered top-level
#   and all requirements of these perl ports need to be built (recursively)
#
# file: ./dead-homepage.list
#
#   This is a list of perl modules that have 404 URLS for their homepages.
#   The homepage value will be overridden to "none"
#
# directory: /tmp/rubygems/build-queue
#
#   This directory holds zero length files with the same names as the rubygems.
#   These are recursive dependencies of the top_ports.list that have yet to be
#   built
#
# directory: /tmp/rubygems/completed
#
#   This directory holds zero length files with the same names as the rubygems.
#   These have already been generated.  They are moved from the build-queue to
#   this directory.
#
# directory: /tmp/rubygems/failed-to-build
#
#   This directory holds files with the same names as the rubygems.
#   These ports failed to generate from some reason.  The reason may be
#   elaborated in the files (so they may not be zero-length like the others)

[ -n "${DEBUG_MK_SCRIPTS}" -o -n "${DEBUG_MK_SCRIPTS_MAKESUM}" ] && set -x

pathtoexec=$(realpath $0)
thisdir=$(dirname ${pathtoexec})
tmpdir=/tmp/rubygems
failed=${tmpdir}/failed-to-build
built=${tmpdir}/completed
queue=${tmpdir}/build-queue

# mark built/failed
mark_result()
{
   local res=${1}
   local gem=${2}
   if [ ${res} -eq 0 ]; then
      touch ${built}/${gem}
   else
      touch ${failed}/${gem}
   fi
}

# get list of all rubygems and their latest versions
/bin/sh ${thisdir}/dump_latest.sh

# empty and recreate work directories
rm -rf ${queue} ${built} ${failed}
mkdir -p ${queue} ${built} ${failed}

# iterate through top-level list
while read line; do
   ${thisdir}/single_rubygem.sh ${line}
   mark_result $? ${line}
done < ${thisdir}/top_ports.list

# Now search queue over and over until there are no new ports added
while true; do
   dir_is_empty=$(find ${queue} -depth -maxdepth 0 -empty)
   if [ -n "${dir_is_empty}" ]; then
      exit 0;
   fi
   list=$(cd ${queue} && find * -type f)
   for item in ${list}; do
      ${thisdir}/single_rubygem.sh ${item}
      mark_result $? ${item}
      rm ${queue}/${item}
   done
done
