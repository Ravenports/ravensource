#!/bin/sh
#
# This script regenerates all listed perl ports
#
# script: ./produce_latest_module_candidates.sh
#
#   This creates /tmp/cpan-work/latest_candidates.txt, which is a filtered
#   list of CPAN modules that pass rudimentary validity checks
#
# file: ./top_ports.list
#
#   This is a list of perl ports that we want.  They are considered top-level
#   and all requirements of these perl ports need to be built (recursively)
#
# file: /tmp/cpan-work/latest_candidates.txt
#
#   This is the filted list produced by produce_latest_module_candidates.sh
#   script.
#
# directory: /tmp/cpan-work/build-queue
#
#   This directory holds zero length files with the same names as perl
#   modules.  These are recursive dependencies of the top_ports.list that
#   have yet to be built
#
# directory: /tmp/cpan-work/completed
#
#   This directory holds zero length files with the same names as perl
#   modules.  These have already been generated.  They are moved from the
#   build-queue to here.
#
# directory: /tmp/cpan-work/failed-to-build
#
#   This directory holds files with the same names as the perl modules.
#   These ports failed to generate from some reason.  The reason may be
#   elaborated in the files (so they may not be zero-length like the others)
#

[ -n "${DEBUG_MK_SCRIPTS}" -o -n "${DEBUG_MK_SCRIPTS_MAKESUM}" ] && set -x

pathtoexec=$(realpath $0)
thisdir=$(dirname ${pathtoexec})
tmpdir=/tmp/cpan-work
failed=${tmpdir}/failed-to-build
built=${tmpdir}/completed
queue=${tmpdir}/build-queue
meta_json=${tmpdir}/meta.json
meta_yaml=${tmpdir}/meta.yaml
build_pl=${tmpdir}/Build.PL
RAVENADM=/home/marino/ravenadm/build/ravenadm # /raven/bin/ravenadm
# ENTRY_LIST=${tmpdir}/latest_candidates.txt
ENTRY_LIST=${tmpdir}/02packages.details.txt

perlv1="5.24.1"
perlv2="5.22.2"

# Determines port namebase based on perl module namespace
convert_to_port_name()
{
   local perlname=${1}
   echo ${perlname} | awk '{ gsub(/::/,"-",$1); print "perl-" $1 }'
}

# URL to download META.json or META.yaml
cpansearch_url()
{
   local perlname=${1}
   local urlstub="http://cpansearch.perl.org/src/"
   awk -vperlname=${perlname} -vstub="${urlstub}" '\
{ if ($1 == perlname) {\
    split($3, ray, "/"); \
    numparts = split(ray[4], tarball, "-"); \
    for (x = 1; x < numparts; x++) { \
      lastdir = lastdir tarball[x] "-"; \
    } \
    numseg = split (tarball[numparts], seg, "."); \
    if ((numseg > 2) && (seg[numseg - 1] == "tar")) { \
      last_seg = numseg - 2; \
    } else { \
      last_seg = numseg - 1; \
    } \
    for (x = 1; x <= last_seg; x++) { \
       if (x > 1) { lastdir = lastdir "." }; \
       lastdir = lastdir seg[x]; \
    } \
    print stub ray[3] "/" lastdir; \
    exit; \
  }\
}' ${ENTRY_LIST}
}

# suffix for CPAN/ID: master site
# the second word is the tarball
author_and_tarball()
{
   local perlname=${1}
   awk -vperlname=${perlname} '\
{ if ($1 == perlname) {\
    split($3, ray, "/"); \
    print ray[1] "/" ray[2] "/" ray[3] " " ray[4]
    exit; \
  }\
}' ${ENTRY_LIST}
}

# target directory in ravensource
get_bucketname()
{
	local portname=${1}
	local raw=$(${RAVENADM} locate ${portname})
	local bucket=$(echo ${raw} | awk -F '/' \
	   '{ for (x=1;x<=NF;x++) if (substr($x,1,7) == "bucket_") print $x}')
	echo ${bucket}/${portname}
}

# full path in ravensource
ravensource_dir()
{
	local local_bucketname=${1}
	echo "${thisdir}/../../${local_bucketname}"
}

# generate ravensource port subroutine
generate_ravensource()
{
   local perl_module=${1}
   base_url=$(cpansearch_url ${perl_module})
   if [ -z "${base_url}" ]; then
      echo "failed to find entry for ${perl_module}"
      touch ${failed}/${perl_module}
      continue
   fi
   perl_builder="configure"
   port_author=$(author_and_tarball ${perl_module})
   port_name=$(convert_to_port_name ${perl_module})
   bucketname=$(get_bucketname ${port_name})
   ravsrc_dir=$(ravensource_dir ${bucketname})
   rm -f ${meta_json} ${meta_yaml} ${build_pl}
   mkdir -p ${ravsrc_dir}/descriptions
   fetch ${base_url}/Build.PL -o ${build_pl} 2>/dev/null
   if [ $? -eq 0 ]; then
   	grep -q "Module::Build::Tiny" ${build_pl}
   	if [ $? -eq 0 ]; then
   	   perl_builder="buildmodtiny"
   	else
   	   perl_builder="buildmod"
   	fi
   fi
   fetch ${base_url}/META.json -o ${meta_json} 2>/dev/null
   if [ $? -eq 0 ]; then
      echo "Retrieved meta.json for ${port_name}"
      perl ${thisdir}/write_port_from_json.pl ${port_name} ${port_author} ${perl_builder} ${ravsrc_dir}
      result=$?
   else
      fetch ${base_url}/META.yml -o ${meta_yaml} 2>/dev/null
      if [ $? -eq 0 ]; then
         echo "Retrieved meta.yaml for ${port_name}"
         perl ${thisdir}/write_port_from_yaml.pl ${port_name} ${port_author} ${perl_builder} ${ravsrc_dir}
         result=$?
      else
         echo "No META files found for ${perl_module} at ${base_url}"
         touch ${failed}/${perl_module}
         continue
      fi
   fi
   if [ ${result} -eq 0 ]; then
      silent_cmd=$(cd ${ravsrc_dir} && ${RAVENADM} dev distinfo)
      echo "          Gen ${bucketname}"
      touch ${built}/${perl_module}
   else
      touch ${failed}/${perl_module}
   fi
}

# Get filtered list of 35,000 perl ports and their latest versions
# ${thisdir}/produce_latest_module_candidates.sh

# empty and recreate work directories
rm -rf ${queue} ${built} ${failed}
mkdir -p ${queue} ${built} ${failed}

# iterate through top-level list (first time)
while read line; do
   check_core=$(corelist -d "${line}" -v "${perlv2}" | awk '{print $2}')
   if [ "${check_core}" != "undef" ]; then
      check_core=$(corelist -d "${line}" -v "${perlv1}" | awk '{print $2}')
      if [ "${check_core}" != "undef" ]; then
         echo "Update top ports list.  ${line} is part of core on perl ${perlv1} and ${perlv2}"
         exit 1;
      fi
   fi
done < ${thisdir}/top_ports.list

# iterate through top-level list (second time)
while read line; do
   generate_ravensource ${line}
done < ${thisdir}/top_ports.list

# Now search queue over and over until there are no new ports added
while true; do
   dir_is_empty=$(find ${queue} -depth -maxdepth 0 -empty)
   if [ -n "${dir_is_empty}" ]; then
      exit 0;
   fi
   list=$(cd ${queue} && find * -type f)
   for item in ${list}; do
      generate_ravensource ${item}
      rm ${queue}/${item}
   done
done
