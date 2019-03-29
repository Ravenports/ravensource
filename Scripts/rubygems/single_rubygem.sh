#!/bin/sh
#
# This script regenerates a single rubygem port given the rubygem name.
# It is called by ./regenerate_rubygems.sh normally, but it operates as
# a standalone script as well.  See extended comments in regenerate_rubygems.sh
#
# argument 1: ruby gem name
# argument 2: optional, "force" to ignore "done" in cache and force rebuild

[ -n "${DEBUG_MK_SCRIPTS}" -o -n "${DEBUG_MK_SCRIPTS_MAKESUM}" ] && set -x

RUBYEXE=ruby25
pathtoexec=$(realpath $0)
thisdir=$(dirname ${pathtoexec})
tmpdir=/tmp/rubygems
queue=${tmpdir}/build-queue
built=${tmpdir}/completed
crash=${tmpdir}/failed-to-build
RAVENADM=/raven/bin/ravenadm
DEADLIST=${thisdir}/dead-homepage.list
ENTRY_LIST=${tmpdir}/gem_index
NEWPORT=/tmp/ruby-${1}
SPEC=${NEWPORT}/specification
mirror_base=/mech/var/cache/rubygems
specsdir=${mirror_base}/specs
reqsdir=${mirror_base}/reqs
gemline="gs = Marshal.load Gem::Util.inflate File.read '${specsdir}"
min_ruby24="2.4.5"
min_ruby25="2.5.3"
min_ruby26="2.6.0"
secondarg="$2"
#VARIANTS=

if [ $# -lt 1 ]; then
   echo "usage: single_rubygem.sh <gem-name>"
   exit 1;
fi

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
   # work around nokogiri version regression manually
   awk -vgem=$gem '{ if (gem == "nokogiri") { print "1.10.2"; exit}; \
   	if ($1 == gem) { print $2; exit }}' ${ENTRY_LIST}
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
	if [ ! -f ${specsdir}/${gemspec} ]; then
		echo "downloading ${gemspec}"
		fetch http://rubygems.org/quick/Marshal.4.8/${gemspec} -o ${specsdir}
	fi
}

# download requirements for exact version of gemspec (if not already cached)
download_gemspec_requirements()
{
	local reqfile=${1}-${2}.requirements
	local pattern="/^${1}\$/"
	if [ ! -f ${reqsdir}/${reqfile} -o "${secondarg}" = "force" ]; then
		echo "Downloading requirements for ${1} version ${2}"
		#echo "executing gem dependency ${pattern} --remote --version=${2}"
		gem dependency ${pattern} --remote --version=${2} > ${reqsdir}/${reqfile}
	fi
}

# return summary (limit to 50 chars later)
obtain_summary()
{
	local gemspec=${1}-${2}.gemspec.rz
	summary=$($RUBYEXE -e "${gemline}/${gemspec}'; puts gs.summary" | sed 's/[ ]*$//')
	if [ -z "${summary}" ]; then
		echo "No description provided"
	else
		echo "${summary}"
	fi
}

# create long description file
create_description()
{
	local gemspec=${1}-${2}.gemspec.rz
	mkdir -p ${NEWPORT}/descriptions
	$RUBYEXE -e "${gemline}/${gemspec}'; puts gs.description" | \
		awk '{ if (!found && NF==0) { next } found=1; print}' | \
		fold -s -w 75 | sed 's/[[:blank:]]*$//' | awk 'NR <= 100' \
		> ${NEWPORT}/descriptions/desc.single
	if [ ! -s ${NEWPORT}/descriptions/desc.single ]; then
		obtain_summary ${1} ${2} | awk 'NR <= 100' \
		> ${NEWPORT}/descriptions/desc.single
	fi	
}

# return homepage (affected by dead status)
obtain_homepage()
{
	local gemspec=${1}-${2}.gemspec.rz
	if [ "${3}" = "ok" ]; then
	   home=$($RUBYEXE -e "${gemline}/${gemspec}'; puts gs.homepage")
	   if [ -z "${home}" ]; then
	      echo "none"
	   else
	      echo ${home}
	   fi
	else
	   echo "none";
	fi
}

# return required ruby version (minimum?)
obtain_ruby_requirement()
{
	local gemspec=${1}-${2}.gemspec.rz
	$RUBYEXE -e "${gemline}/${gemspec}'; puts gs.required_ruby_version"	
}

get_filtered_url() {
   url=$(obtain_homepage ${1} ${2} ${3})
   case ${url} in
      http://github.com/* | http://bitbucket.org/* | \
      http://docs.openstack.org* | http://banisterfiend.wordpress.com* | \
      http://wiki.github.com/* | \
      http://*.github.io* | http://rubyonrails.org* | http://bundler.io*)
         echo ${url} | sed -e "s/^http:/https:/"
         ;;
      *) echo ${url} ;;
   esac
}

determine_variants() {
   local vrt
   local rubyreq=$(obtain_ruby_requirement ${1} ${2})  # >= 0, >= 1.9.2
   local good24=$(echo "${rubyreq}" | awk -vmin=${min_ruby24} '{ print ($2 < min ? "good" : "bad")}')
   if [ "${good24}" == "good" ]; then
      vrt="${vrt} v24"
   fi
   local good25=$(echo "${rubyreq}" | awk -vmin=${min_ruby25} '{ print ($2 < min ? "good" : "bad")}')
   if [ "${good25}" == "good" ]; then
      vrt="${vrt} v25"
   fi
   local good26=$(echo "${rubyreq}" | awk -vmin=${min_ruby26} '{ print ($2 < min ? "good" : "bad")}')
   if [ "${good26}" == "good" ]; then
      vrt="${vrt} v26"
   fi
   for v in ${vrt}; do
      if [ -z "${VARIANTS}" ]; then
         VARIANTS=${v};
      else
         VARIANTS="${VARIANTS} ${v}";
      fi
   done
}

dump_descriptions() {
   local v sdesc
   sdesc=$(obtain_summary ${1} ${2}| awk -vmodule=${1} '\
function chop(summary,front) {\
 ufront=toupper(front);\
 len=length(ufront);\
 if ((len < length(summary)) && (toupper(substr(summary,1,len)) == ufront)) \
   return substr(summary, len + 1);\
 else\
   return summary;\
}\
function nodot(summary) {\
 len=length(summary);\
 if (substr(summary,len,1) == ".")\
   return substr(summary, 1, len-1);\
 else
   return summary;\
}\
{\
 raw=chop($0,  "a ");\
 raw=chop(raw, "an ");\
 raw=chop(raw, sprintf ("%s is a ", module));\
 raw=chop(raw, sprintf ("%s is an ", module));\
 raw=chop(raw, sprintf ("%s - ", module));\
 raw=chop(raw, "the ");\
 raw=nodot(raw);\
 final=toupper(substr(raw, 1, 1)) substr(raw, 2); \
 print substr (final, 1, 44) }')
   for v in ${VARIANTS}; do
      echo "SDESC[${v}]=		${sdesc} (${v})"
   done
}

dump_subpackages() {
   local v
   for v in ${VARIANTS}; do
      echo "SPKGS[${v}]=		single"
   done
}

dump_vopts() {
   local v
   for v in ${VARIANTS}; do
      echo ${VARIANTS} | awk -v variant=${v} '{\
  printf ("VOPTS[%s]=		", variant); \
  for (x=1; x<=NF; x++) { \
    printf ("%s%s=%s",\
      x == 1 ? "" : " ",\
      sprintf("RUBY%s", substr($x, 2)),\
      $x == variant ? "ON" : "OFF"\
    )\
  };\
  printf ("\n");
}'
   done
}

get_available_options() {
   echo ${VARIANTS} | awk '{ gsub(/v/, "RUBY");  print }'
}

handle_licenses() {
	# placeholder, do nothing for now
}

dump_dependencies_as_comments() {
   local reqfile=${1}-${2}.requirements
   echo "# Requirements specified by gem dependency --remote --version command"
   awk '{ if (NR>1) {if (length ($1) > 0) print "# " $0 }}' ${reqsdir}/${reqfile}
}

dump_buildrun_options() {
   local reqfile=${1}-${2}.requirements
   for v in ${VARIANTS}; do
      awk -v variant=${v} '\
BEGIN {\
  virgin = 1; \
  rubyXX=sprintf("RUBY%s", substr(variant, 2));
  printf ("\n[%s].USES_ON=			gem:%s\n", \
     rubyXX, variant);\
}\
{\
  if (NR > 1) {
    if (length ($1) > 0) {\
      dev = index ($0, ", development");\
      if (dev == 0) {\
         if ($1 == "bundler") dev=1;\
      };\
      if (dev == 0) {\
        if (virgin) {\
          printf ("[%s].BUILDRUN_DEPENDS_ON=		", rubyXX);\
        };\
        package=sprintf("ruby-%s", $1);\
        if (package in seen == 0) { \
          printf ("%s%s:single:%s\n",\
            virgin ? "" : "					",\
            package,\
            variant);\
        };\
        seen[package]=1;\
        virgin=0;\
      };\
    };\
  };\
}' ${reqsdir}/${reqfile}
   done
}

populate_queue() {
   local qlist
   local reqfile=${1}-${2}.requirements
   if [ -d ${queue} ]; then
      qlist=$(awk '{\
 if (NR > 1) {\
   if (NF > 1) {\
     package=$1;\
     if (package in seen == 0) {\
       dev = index ($0, ", development");\
       if (dev == 0) {\
          if ($1 == "bundler") dev=1;\
       };\
       if (dev == 0) { print $1 };\
     };\
     seen[package]=1;\
   };
 };
}' ${reqsdir}/${reqfile})
     for gem in ${qlist}; do
       if [ ! -f ${queue}/${gem} ]; then
         if [ ! -f ${built}/${gem} ]; then
           if [ ! -f ${crash}/${gem} ]; then
             touch ${queue}/${gem}
           fi
         fi
       fi
     done
   fi
}

# generate ravensource routine
generate_ravensource()
{
   local module=${1}

   if [ -f ${built}/${module} -a "$secondarg" != "force" ]; then
      echo "done!     ${module}"
      return;
   fi
   
   local latest_version=$(extract_version ${module})
   local port_name=ruby-${module}
   local bucketname=$(get_bucketname ${port_name})
   local ravsrc_dir=$(ravensource_dir ${bucketname})
   local hp_status=$(homepage_status ${port_name})
   local tarball=${module}-${latest_version}.gem	# might need to be overridable
   local manualbit
   download_gemspec ${module} "${latest_version}"
   download_gemspec_requirements ${module} "${latest_version}"
   if [ -f ${specsdir}/${module}-${latest_version}.gemspec.rz ]; then
   else
      echo "failed to download ${module} gemspec version ${latest_version}, skipping ..."
      exit 1
   fi

   if [ -f "${ravsrc_dir}/specification.manual" ]; then
      manualbit=$(cat ${ravsrc_dir}/specification.manual)
   fi
   determine_variants ${module} "${latest_version}"
   create_description ${module} "${latest_version}"

   cat <<EOF > ${SPEC}
DEF[PORTVERSION]=	${latest_version}
# ------------------------------------------------------------------------

NAMEBASE=		ruby-${module}
VERSION=		\${PORTVERSION}
KEYWORDS=		ruby
VARIANTS=		${VARIANTS}
$(dump_descriptions ${module} ${latest_version})
HOMEPAGE=		$(get_filtered_url ${module} ${latest_version} ${hp_status})
CONTACT=		Ruby_Automaton[ruby@ironwolf.systems]

DOWNLOAD_GROUPS=	main
SITES[main]=		RUBYGEMS/
DISTFILE[1]=		${tarball}:main
DIST_SUBDIR=		ruby

$(dump_subpackages)

OPTIONS_AVAILABLE=	$(get_available_options)
OPTIONS_STANDARD=	none
$(dump_vopts)
$(handle_licenses)
GENERATED=		yes

$(dump_dependencies_as_comments ${module} ${latest_version})

DISTNAME=		${module}-\${PORTVERSION}
$(dump_buildrun_options ${module} ${latest_version})
${manualbit}
EOF

   (cd ${NEWPORT} && /raven/bin/ravenadm dev distinfo)
   echo "Overwriting ruby-${module}."
   mkdir -p ${ravsrc_dir}
   cp -a ${NEWPORT}/* ${ravsrc_dir}/
   rm -rf ${NEWPORT}
   populate_queue ${module} "${latest_version}"
}

mkdir -p ${mirror_base}/specs ${mirror_base}/reqs
generate_ravensource ${1}
