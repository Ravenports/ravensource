#!/bin/sh
#
# This script regenerates all listed rubygem ports
#
# script: ./dump_latest.sh
#
#   This creates /tmp/rubygems/gem_index, which comes from data transformed
#   from the latest rubygem versions spec file
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
/tmpdir=/tmp/rubygems
failed=${tmpdir}/failed-to-build
built=${tmpdir}/completed
queue=${tmpdir}/build-queue
RAVENADM=/raven/bin/ravenadm
DEADLIST=${thisdir}/dead-homepage.list
mirror_base="/mech/var/cache/rubygems/"
gemline="gs = Marshal.load Gem.inflate File.read '${mirror_base}"
min_ruby23="2.3.5"
min_ruby24="2.4.2"
#VARIANTS=

# return "ok" or "dead".
# "dead" means the port has been manually marked for a dead homepage
homepage_status()
{
   awk -vportname="${1}" '{ if (portname == $1) { found = 1 }} \
END { print (found) ? "dead" : "ok"}' ${DEADLIST}
}

# obtain the the latest version
extract_version()
{
   local gem=${1}
   awk -vgem=$gem '{ if ($1 == gem) { print $2; exit }}' ${ENTRY_LIST}
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

# download gemspec (if not already cached)
download_gemspec()
{
	local gemspec=${1}-${2}.gemspec.rz
	if [ ! -f ${mirror_base}/${gemspec} ]; then
		fetch http://rubygems.org/quick/Marshal.4.8/${gemspec} -o ${mirror_base}
	fi
}

# return summary (limit to 50 chars later)
obtain_summary()
{
	local gemspec=${1}-${2}.gemspec.rz
	ruby24 -e "${gemline}/${gemspec}'; puts gs.summary"
}

# create long description file
create_description()
{
	local gemspec=${1}-${2}.gemspec.rz
	local NEWPORT=${3}
	mkdir -p ${NEWPORT}/descriptions
	ruby24 -e "${gemline}/${gemspec}'; puts gs.description" | awk 'NR <= 100' \
		> ${NEWPORT}/descriptions/desc.single
	if [ ! -s ${NEWPORT}/descriptions/desc.single ]; then
		obtain_summary | awk 'NR <= 100' > ${NEWPORT}/descriptions/desc.single
	fi	
}

# return homepage (affected by dead status)
obtain_homepage()
{
	local gemspec=${1}-${2}.gemspec.rz
	if [ "${3}" = "ok" ]; then
	   ruby24 -e "${gemline}/${gemspec}'; puts gs.homepage"
	else
	   echo "none";
	fi
}

# return required ruby version (minimum?)
obtain_ruby_requirement()
{
	local gemspec=${1}-${2}.gemspec.rz
	ruby24 -e "${gemline}/${gemspec}'; puts gs.required_ruby_version"	
}

get_filtered_url() {
   url=$(get_url)
   case ${url} in
      http://github.com/* | http://bitbucket.org/* | \
      http://certifi.io/* | http://docs.openstack.org/* )
         echo ${url} | sed -e "s/^http:/https:/"
         ;;
      *) echo ${url} ;;
   esac
}

determine_variants() {
   local vrt
   local rubyreq=$(obtain_ruby_requirement ${1} ${2})  # >= 0, >= 1.9.2
   local good23=$(echo "${rubyreq}" | awk -vmin=${min_ruby23} '{ print ($2 < min ? "good" : "bad")}')
   if [ "${good23}" == "good" ]; then
      vrt="v23"
   fi
   local good24=$(echo "${rubyreq}" | awk -vmin=${min_ruby24} '{ print ($2 < min ? "good" : "bad")}')
   if [ "${good24}" == "good" ]; then
      vrt="v24"
   fi
   for v in ${vrt}; do
      if [ -z "${VARIANTS}" ]; then
         VARIANTS=${v};
      else
         VARIANTS="${VARIANTS} ${v}";
      fi
   done
}

# generate ravensource port subroutine
generate_ravensource()
{
   local ruby_module=${1}

   if [ -f ${built}/${ruby_module} ]; then
      echo "done!     ${ruby_module}"
      return;
   fi
   
   local latest_version=$(extract_version ${ruby_module})
   local port_name=ruby-${ruby_module}
   local bucketname=$(get_bucketname ${port_name})
   local ravsrc_dir=$(ravensource_dir ${bucketname})
   local hp_status=$(homepage_status ${port_name})
   local tmpport=${tmpdir}/${port_name}
   local manualbit
   download_gemspec ${ruby_module} "${latest_version}"
   if [ -f ${mirror_base}/${ruby_module}-${latest_version}.gemspec.rz ]; then
   else
      echo "failed to download ${ruby_module} gemspec version ${latest_version}, skipping ..."
   fi

   if [ -f "${ravsrc_dir}/specification.manual" ]; then
      manualbit=$(cat ${ravsrc_dir}/specification.manual)
   fi
   determine_variants ${ruby_module} "${latest_version}"
   create_description ${ruby_module} "${latest_version}" "${tmpport}"
   
}

# get list of all rubygems and their latest versions
/bin/sh ${thisdir}/dump_latest.sh

# empty and recreate work directories
rm -rf ${queue} ${built} ${failed}
mkdir -p ${queue} ${built} ${failed} ${mirror_base}

# iterate through top-level list
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
