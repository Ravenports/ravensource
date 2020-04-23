#!/bin/sh
#
# This script regenerates all listed perl ports
#
# script: ./produce_latest_module_candidates.sh
#
#   This creates /tmp/cpan-work/latest_candidates.txt, which is a filtered
#   list of CPAN modules that pass rudimentary validity checks
#
# file: ./list.top_ports
#
#   This is a list of perl ports that we want.  They are considered top-level
#   and all requirements of these perl ports need to be built (recursively)
#
# file: ./list.dead-homepage
#
#   This is a list of perl modules that have 404 URLS for their homepages.
#   The homepage value will be overridden to "none"
#
# file: /tmp/cpan-work/latest_candidates.txt
#
#   This is the filted list produced by produce_latest_module_candidates.sh
#   script.
#
# directory: /tmp/cpan-work/build-queue
#
#   This directory holds zero length files with the same names as perl
#   modules.  These are recursive dependencies of the list.top_ports that
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
# Install:
# perl-5.30-complete-standard
# perl-File-Slurp-single-530
# perl-JSON-single-530

[ -n "${DEBUG_MK_SCRIPTS}" -o -n "${DEBUG_MK_SCRIPTS_MAKESUM}" ] && set -x

export PATH="/sbin:/bin:/usr/sbin:/usr/bin:/raven/sbin:/raven/bin"

pathtoexec=$(realpath $0)
thisdir=$(dirname ${pathtoexec})
tmpdir=/tmp/cpan-work
failed=${tmpdir}/failed-to-build
built=${tmpdir}/completed
queue=${tmpdir}/build-queue
RAVENADM=/raven/bin/ravenadm
# ENTRY_LIST=${tmpdir}/latest_candidates.txt
ENTRY_LIST=${tmpdir}/02packages.details.txt
DEADLIST=${thisdir}/list.dead-homepage
SUMOVERLIST=${thisdir}/list.summary-override
DESCOVERLIST=${thisdir}/list.description-override
RMVLIST=${thisdir}/list.bad-v
urlstub="https://st.aticpan.org/source/"
mirror_base="/mech/var/cache/cpan/"

perlv1="5.30.1"
perlv2="5.28.2"

if [ "${1}" == "check-core" ]; then
   check_core=1;
else
   check_core=0;
fi

# obtain the information line (avoids repeated long scans)
extract_info()
{
   local perlname=${1}
   if [ $perlname = "File::chdir" ]
   then
      echo "File::chdir  0.1011  D/DA/DAGOLDEN/File-chdir-0.1011.tar.gz"
#   elif [ $perlname = "Inline" ]
#   then
#      echo "Inline  0.85  I/IN/INGY/Inline-0.85.tar.gz"
   else
      awk -vperlname=$perlname \
      '{ if ($1 == perlname) { print; exit }}' ${ENTRY_LIST}
   fi
}

# URL to download META.json or META.yaml
cpansearch_url()
{
   echo ${1} | awk '\
{ \
  # every now and then, the url is the 5th element, not the 4th
  lastrock = split($3, ray, "/"); \
  numparts = split(ray[lastrock], tarball, "-"); \
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
  print ray[3] "/" lastdir; \
}'
}

# suffix for CPAN/ID: master site
# the second word is the tarball
author_and_tarball()
{
   echo ${1} | awk '\
{ \
  lastrock = split($3, ray, "/"); \
  author = ray[1]; \
  for (x = 2; x < lastrock; x++) { author = author "/" ray[x] }
  print author " " ray[lastrock]; \
}'
}

# There is a many-to-one relationship between modules
# and tarballs, so the portname has to be based on tarball filename.
extract_portname()
{
   echo ${1} | awk '\
{ \
  lastrock = split($3, ray, "/"); \
  numparts = split(ray[lastrock], tarball, "-"); \
  for (x = 1; x < numparts; x++) { \
    if (x > 1) { lastdir = lastdir "-" };
    lastdir = lastdir tarball[x]; \
  } \
  print "perl-" lastdir; \
}'
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

# mark all modules connected to tarball in given directory
mark_all_modules()
{
   local target_dir="$1"
   local author="$2"
   local tarball="$3"
   modules=$(awk -vtarball="${author}/${tarball}" '\
{ \
  if ($3 == tarball) { print $1 } \
}' ${ENTRY_LIST})

   for module in ${modules}; do
      touch ${target_dir}/${module}
   done
}

# return "ok" or "dead".
# "dead" means the port has been manually marked for a dead homepage
homepage_status()
{
   awk -vportname="${1}" '{ if (portname == $1) { found = 1 }} \
END { print (found) ? "dead" : "ok"}' ${DEADLIST}
}

# return "ok" or "rmv"
rmv_status()
{
   awk -vportname="${1}" '{ if (portname == $1) { found = 1 }} \
END { print (found) ? "rmv" : "ok"}' ${RMVLIST}
}

# return summary string or blank
summary_override()
{
   awk -vportname="${1}" -F"\t" '{ if (portname == $1) { print $2 ; exit 0 }}' ${SUMOVERLIST}
}

# return description string or blank
description_override()
{
   awk -vportname="${1}" -F"\t" '{ if (portname == $1) { print $2 ; exit 0 }}' ${DESCOVERLIST}
}

# generate ravensource port subroutine
generate_ravensource()
{
   local perl_module=${1}

   if [ -f ${built}/${perl_module} ]; then
      echo "done!     ${perl_module}"
      return;
   fi

   local perl_builder="configure"
   local index_info=$(extract_info ${perl_module})
   local port_name=$(extract_portname "${index_info}")
   local bucketname=$(get_bucketname ${port_name})
   local ravsrc_dir=$(ravensource_dir ${bucketname})
   local port_author=$(author_and_tarball "${index_info}")
   local hp_status=$(homepage_status ${port_name})
   local distgood=$(rmv_status ${port_name})
   local sumover=$(summary_override ${port_name})
   local descover=$(description_override ${port_name})

   local url_tail=$(cpansearch_url "${index_info}")   
   if [ -z "${url_tail}" ]; then
      echo "failed to find entry for ${perl_module}"
      touch ${failed}/${perl_module}
      return
   fi

   local base_url="${urlstub}${url_tail}"
   local mirror_url="${mirror_base}${url_tail}"

   meta_json=${mirror_url}/meta.json
   meta_yaml=${mirror_url}/meta.yaml
   build_pl=${mirror_url}/Build.PL
   no_build_pl=${mirror_url}/No_Perl_Build

   mkdir -p ${mirror_url}
   mkdir -p ${ravsrc_dir}/descriptions

   if [ ! -f ${no_build_pl} ]; then
      if [ -f ${build_pl} ]; then
         fetch_result=0;
      else
         env SSL_NO_VERIFY_PEER=1 fetch ${base_url}/Build.PL -o ${build_pl} 2>/dev/null
         fetch_result=$?
      fi
      if [ ${fetch_result} -eq 0 ]; then
         grep -q "Module::Build::Tiny" ${build_pl}
           if [ $? -eq 0 ]; then
              perl_builder="buildmodtiny,run"
           else
              perl_builder="buildmod,run"
           fi
      else
         touch ${no_build_pl}
      fi
   fi

   cached=0   
   if [ -f ${meta_json} ]; then
      echo "cached    meta.json for ${port_name} found"
      perl ${thisdir}/write_port_from_json.pl ${port_name} ${port_author} ${perl_builder} ${ravsrc_dir} "${meta_json}" ${hp_status} ${distgood} "${sumover}" "${descover}"
      result=$?
      cached=1
   else
      if [ -f ${meta_yaml} ]; then
         echo "cached    meta.yaml for ${port_name} found"
         perl ${thisdir}/write_port_from_yaml.pl ${port_name} ${port_author} ${perl_builder} ${ravsrc_dir} "${meta_yaml}" ${hp_status} "${sumover}" "${descover}"
         result=$?
         cached=1
      else
         # We've got no meta files cached.
         # Either this port has none, or we haven't downloaded them yet.
         # check remotely for meta.json, then meta.yaml, then fall back to no meta files
         env SSL_NO_VERIFY_PEER=1 fetch ${base_url}/META.json -o ${meta_json} # 2>/dev/null
         if [ $? -eq 0 ]; then
            echo "Retrieved meta.json for ${port_name}"
            perl ${thisdir}/write_port_from_json.pl ${port_name} ${port_author} ${perl_builder} ${ravsrc_dir} "${meta_json}" ${hp_status} ${distgood} "${sumover}" "${descover}"
            result=$?
         else
            env SSL_NO_VERIFY_PEER=1 fetch ${base_url}/META.yml -o ${meta_yaml} 2>/dev/null
            if [ $? -eq 0 ]; then
               echo "Retrieved meta.yaml for ${port_name}"
               perl ${thisdir}/write_port_from_yaml.pl ${port_name} ${port_author} ${perl_builder} ${ravsrc_dir} "${meta_yaml}" ${hp_status} "${sumover}" "${descover}"
               result=$?
            else
               echo "No META files found for ${perl_module} at ${base_url}"
               perl ${thisdir}/write_port_without_meta.pl ${port_name} ${port_author} ${perl_builder} ${ravsrc_dir} "${sumover}" "${descover}"
               result=$?
            fi
         fi
      fi
   fi

   if [ ${result} -eq 0 ]; then
      if [ $cached -eq 0 ]; then
         silent_cmd=$(cd ${ravsrc_dir} && ${RAVENADM} dev distinfo)
      fi
      echo "          Gen ${bucketname}"
      mark_all_modules "${built}" ${port_author}
   else
      mark_all_modules "${failed}" ${port_author}
   fi
}

# Get filtered list of 35,000 perl ports and their latest versions
${thisdir}/produce_latest_module_candidates.sh

# empty and recreate work directories
rm -rf ${queue} ${built} ${failed}
mkdir -p ${queue} ${built} ${failed}

# iterate through top-level list (first time)
if [ $check_core -eq 1 ]; then
 while read line; do
   check_core=$(corelist -d "${line}" -v "${perlv2}" | awk '{print $2}')
   if [ "${check_core}" != "undef" ]; then
      check_core=$(corelist -d "${line}" -v "${perlv1}" | awk '{print $2}')
      if [ "${check_core}" != "undef" ]; then
         echo "Update top ports list.  ${line} is part of core on perl ${perlv1} and ${perlv2}"
         exit 1;
      fi
   fi
 done < ${thisdir}/list.top_ports
fi

# iterate through top-level list (second time)
while read line; do
   generate_ravensource ${line}
done < ${thisdir}/list.top_ports

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
