#!/bin/sh
#
# This script takes a Python Package Index name as an argument and
# then creates/overwrites the source port after querying the website
# and downloading the latest tarball for querying setup.py
#

[ -n "${DEBUG_MK_SCRIPTS}" -o -n "${DEBUG_MK_SCRIPTS_MAKESUM}" ] && set -x

usage() {
   echo "Usage: $0 PyPI-name [confirm]"
   echo "If the second argument is not 'confirm', a dry-run is executed."
   echo "If second argument is exactly 'confirm', the source port is created/updated."
   exit 1
}

if [ $# -lt 1 ]; then
   usage;
fi

VERSION=unset
MD5SUM=unset
tarball=unset
PYPINAME=${1}
JSONFILE=/tmp/pypi-${PYPINAME}
NEWPORT=/tmp/python-${PYPINAME}
SPEC=${NEWPORT}/specification
distfiles="/var/ravenports/distfiles"
PYPISITE=https://files.pythonhosted.org/packages/source/
PYPISIT2=https://pypi.python.org/packages/source/
PYPITWO=$(echo ${PYPINAME} | awk '{ print substr ($1, 1, 1) "/" $1 }')
#VARIANTS=
#FIRST_SNAKE=
setup=unset
raw_deps=unset
raven_req=unset
pathtoexec=$(realpath $0)
thisdir=$(dirname ${pathtoexec})

acquire_tarball_and_version() {
   local www url summd5

   www="https://pypi.python.org/pypi/${PYPINAME}/json"
   fetch -o ${JSONFILE} ${www}
   if [ $? -ne 0 ]; then
      echo "'${PYPINAME}' doesn't seem to be a valid package name"
      exit 1;
   fi
   VERSION=$(awk -F'"' '/"version":/ { print $4 }' ${JSONFILE})
   MD5SUM=$(awk -v version=${VERSION} -v seek="md5_digest" -f ${thisdir}/md5.awk ${JSONFILE})
   tarball=$(awk -v version=${VERSION} -v seek="filename" -f ${thisdir}/md5.awk ${JSONFILE})

   if [ -f "${distfiles}/${tarball}" ]; then
      summd5=$(md5 -q "${distfiles}/${tarball}")
      if [ "${summd5}" == "${MD5SUM}" ]; then
         echo "Tarball already fetched and digest-verified"
         return;
      fi
   fi

   url="${PYPISITE}${PYPITWO}/${tarball}"
   fetch -o ${distfiles} ${url}
   if [ $? -ne 0 ]; then
      echo "Failed to fetch ${tarball}"
      exit 1
   fi
}

exec_setup() {
  python_program=$1
  arguments=$2
  (cd /tmp/expand/${PYPINAME}-${VERSION}/ && ${python_program} setup.py ${arguments})
}

determine_variants() {
   local vrt
   exec_setup python2.7 --name > /dev/null
   if [ $? -eq 0 ]; then
      vrt="py27"
      [ -z "${FIRST_SNAKE}" ] && FIRST_SNAKE=python2.7
   fi
   exec_setup python3.4 --name > /dev/null
   if [ $? -eq 0 ]; then
      vrt="${vrt} py34"
      [ -z "${FIRST_SNAKE}" ] && FIRST_SNAKE=python3.4
   fi
   exec_setup python3.5 --name > /dev/null
   if [ $? -eq 0 ]; then
      vrt="${vrt} py35"
      [ -z "${FIRST_SNAKE}" ] && FIRST_SNAKE=python3.5
   fi
   for v in ${vrt}; do
      if [ -z "${VARIANTS}" ]; then
         VARIANTS=${v};
      else
         VARIANTS="${VARIANTS} ${v}";
      fi
   done
}

get_description() {
   exec_setup ${FIRST_SNAKE} --description
}

get_url() {
   exec_setup ${FIRST_SNAKE} --url
}

get_available_options() {
   echo ${VARIANTS} | awk '{ print toupper($0) }'
}

dump_descriptions() {
   local v sdesc
   sdesc=$(get_description | awk '{\
 raw=$0; \
 if (substr(raw, 1, 2) == "A ") raw=substr(raw, 3); \
 if (substr(raw, 1, 3) == "An ") raw=substr(raw, 4); \
 final=toupper(substr(raw, 1, 1)) substr(raw, 2); \
 print substr (final, 1, 42) }')
   for v in ${VARIANTS}; do
      echo "SDESC[${v}]=		${sdesc} (PY ${v#py})"
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
      toupper($x),\
      $x == variant ? "ON" : "OFF"\
    )\
  };\
  printf ("\n");
}'
   done
}

create_description() {
   mkdir -p ${NEWPORT}/descriptions
   exec_setup ${FIRST_SNAKE} --long-description \
   	> ${NEWPORT}/descriptions/desc.single
}

dump_variable() {
   local varname data
   varname=$1
   data=$2
   echo ${data} | awk -v varname=${varname} '\
{\
  if (NF) { printf ("%s=		", varname); }\
  for (x=1; x<=NF; x++) {\
    gsub(/\*/, " ", $x);\
    printf ("%s%s\n", x==1?"":"			", $x);\
  }\
}'
}

handle_licenses() {
   local licname licfile
   local arr_license arr_file arr_name
   all_lic=$(exec_setup ${FIRST_SNAKE} --license | \
      awk -F ', ' '{ for (x=1;x<=NF;x++) { gsub (/ /, "*", $x); print $x }}')
   for lic in ${all_lic}; do
   case "${lic}" in
      BSD*) 
        specified=$(awk "/${PYPINAME} / { print \$2 }" ${thisdir}/pypi_bsd_licenses.txt)
        case "${specified}" in
          2) licname="BSD2CLAUSE" ;;
          3) licname="BSD3CLAUSE" ;;
          4) licname="BSD4CLAUSE" ;;
          *) licname="BSDGROUP"   ;;
        esac
        ;;
      *)
        case "${lic}" in
          MIT | ISC) licname="${lic}" ;;
          "public*domain") licname=PUBDOM ;;
          "Python")        licname=PSFL ;;
          "2-Clause*BSD")  licname="BSD2CLAUSE" ;;
          "GPL*3"*)        licname="GPLv3" ;;
          "Apache*2.0")    licname="APACHE20" ;;
          "") ;;
          *) licname="CUSTOM1" ;;
        esac
        ;;
   esac
   for chkfile in LICENSE LICENSE.txt COPYING COPYING3 COPYING.txt LICENSE.rst; do
      if [ -z "${licfile}" ]; then
         if [ -f "/tmp/expand/${PYPINAME}-${VERSION}/${chkfile}" ]; then
            licfile=${chkfile}
         fi
      fi
   done
   if [ -n "${lic}" ]; then
      if [ -n "${licfile}" ]; then
         arr_license="${arr_license} ${licname}:single"
         arr_file="${arr_file} ${licname}:{{WRKSRC}}/${licfile}"
         if [ "${licname}" == "CUSTOM1" ]; then
            arr_name="${arr_name} ${licname}:\"${lic}\""
         fi
      else
         echo "# No license file found for ${lic} license" 
      fi
   else
      echo "# No license specified"
   fi
   done

   dump_variable "LICENSE" "${arr_license}"
   dump_variable "LICENSE_FILE" "${arr_file}"
   dump_variable "LICENSE_NAME" "${arr_name}"
   echo $all_lic | \
   awk '{ if (NF) { printf ("LICENSE_SCHEME=		%s\n", \
        NF>1 ? "multi" : "solo")}}'
}

set_keywords() {
   local topics keywords
   topics=$(exec_setup ${FIRST_SNAKE} --classifiers | grep "^Topic :")
   keywords=python
   if [ -n "`echo ${topics} | grep ':: Utilities'`" ]; then
      keywords="${keywords} devel"
   elif [ -n "`echo ${topics} | grep ':: Software Devel'`" ]; then
      keywords="${keywords} devel"
   fi
   if [ -n "`echo ${topics} | grep ':: Text Processing'`" ]; then
      keywords="${keywords} textproc"
   fi
   if [ -n "`echo ${topics} | grep ':: Multimedia :: Graphics'`" ]; then
      keywords="${keywords} graphics"
   fi
   echo $keywords
}

write_buildrun() {
   local mockfile=/tmp/expand/${PYPINAME}-${VERSION}/obtain-req.py
   raven_req=/tmp/expand/${PYPINAME}-${VERSION}/raven-req.list
   cat <<EOF > ${mockfile}
import unittest.mock
import setuptools

with unittest.mock.patch.object(setuptools, 'setup') as mock_setup:
    import setup

args, kwargs = mock_setup.call_args
print ('\n'.join(kwargs.get('install_requires', [])))
EOF

   (cd /tmp/expand/${PYPINAME}-${VERSION}/ && python3.4 obtain-req.py) \
    2> /dev/null > ${raven_req}
   if [ $? -ne 0 ]; then
      echo "### Python script to obtain dependencies failed! ###";
   fi
}

dump_dependencies_as_comments() {
   echo "# install_requires extracted from setup.py"
   awk '{ if (length ($1) > 0) print "# " $1 }' ${raven_req}
}

dump_buildrun_options() {
   local v
   for v in ${VARIANTS}; do
      awk -F ">" -v variant=${v} '\
function strip_dep(dep) {\
       if (index (dep, "==")) \
       return "python-" substr (dep, 1, index (dep, "=="));\
  else if (index (dep, "!=")) \
       return "python-" substr (dep, 1, index (dep, "!="));\
  else if (index (dep, "<")) \
       return "python-" substr (dep, 1, index (dep, "<"));\
  else \
       return "python-" dep;\
}\
function filter(dep) {\
   if (dep == "python-babel") return "python-Babel";
   else return dep;
}\
BEGIN {\
  virgin = 1; \
  printf ("\n[%s].USES_ON=				python:%s\n", \
     toupper(variant), variant);\
}\
{\
  if (length ($1) > 0) {\
     if (virgin) \
        printf ("[%s].BUILDRUN_DEPENDS_ON=		", toupper(variant));\
     package=filter(strip_dep($1));\
     printf ("%s%s:single:%s\n",\
        virgin ? "" : "					",\
        package,\
        variant);\
   };\
   virgin = 0;\
}' ${raven_req}
   done
}

replace_port() {
	# 1. Create bucket directory
	# 2. copy over:
	#    specification
	#    descriptions/desc.single
	#    distinfo
	# Any other materials like files/*, patches/*, etc. remain
	local raw=$(/raven/bin/ravenadm locate python-${PYPINAME})
	local bucket=$(echo ${raw} | awk -F '/' \
	   '{ for (x=1;x<=NF;x++) if (substr($x,1,7) == "bucket_") print $x}')
	local buckdir="${thisdir}/../${bucket}/python-${PYPINAME}"
	mkdir -p ${buckdir}/descriptions
	mv ${SPEC} ${buckdir}
	mv ${NEWPORT}/descriptions/desc.single ${buckdir}/descriptions
	mv ${NEWPORT}/distinfo ${buckdir}
	rmdir ${NEWPORT}/descriptions
	rmdir ${NEWPORT}
	/raven/bin/ravenadm dev buildsheet ${buckdir} save
}

generate_port() {
   rm -rf ${NEWPORT} /tmp/expand
   mkdir -p ${NEWPORT} /tmp/expand
   (cd /tmp/expand && tar -xf ${distfiles}/${tarball})
   setup=/tmp/expand/${PYPINAME}-${VERSION}/setup.py
   if [ ! -f "${setup}" ]; then
      echo "Setup script '${setup}' is not present";
      exit 1;
   fi
   determine_variants
   create_description
   write_buildrun

   cat <<EOF > ${SPEC}
DEF[PORTVERSION]=	${VERSION}
# ------------------------------------------------------------------------

NAMEBASE=		python-${PYPINAME}
VERSION=		\${PORTVERSION}
KEYWORDS=		$(set_keywords)
VARIANTS=		${VARIANTS}
$(dump_descriptions)
HOMEPAGE=		$(get_url)
CONTACT=		Python_Automaton[python@ironwolf.systems]

DOWNLOAD_GROUPS=	main
SITES[main]=		PYPI/${PYPITWO}
DISTFILE[1]=		${PYPINAME}-\${PORTVERSION}.tar.gz:main

$(dump_subpackages)

OPTIONS_AVAILABLE=	$(get_available_options)
OPTIONS_STANDARD=	none
$(dump_vopts)

$(handle_licenses)

$(dump_dependencies_as_comments)

DISTNAME=		${PYPINAME}-\${PORTVERSION}
$(dump_buildrun_options)
EOF

   (cd ${NEWPORT} && /raven/bin/ravenadm dev distinfo)
   
}

acquire_tarball_and_version
generate_port
replace_port

rm -f ${JSONFILE}
