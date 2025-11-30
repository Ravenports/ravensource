#!/bin/sh
#
# This script copies php84 extensions to phpXY extensions where
# argument 1 is "X" and argument 2 is "Y".
#
# The script invokes "ravenadm dev distinfo" then "ravenadm dev buildsheet"
# to regenerate the extension after preparing it.
#
# Existing entries are skipped unless FORCE is defined in environment

DPATH=$(dirname $0)
MISCDIR=$(cd ${DPATH} && pwd -P)
SCRIPTSDIR=$(dirname ${MISCDIR})
RAVENSRC=$(dirname ${SCRIPTSDIR})
myid=$(id -un)

if [ "${myid}" != "root" ]; then
   echo "Only root is allowed to regenerate ports (which requires using root-only ravenadm)"
   exit 1
fi

if [ $# -lt 2 ]; then
   echo "add php major version as the first argument"
   echo "add php minor version as the second argument"
   return 1
fi

LISTFILE=${MISCDIR}/php.extensions

if [ ! -f ${LISTFILE} ]; then
   echo "The file '${LISTFILE}' does not exist"
   return 1
fi

case "${1}" in
	8|9) ;;	# valid php major version
	*)
	echo "The '${1}' setting is not a valid PHP major version"
	return 1
	;;
esac

case "${2}" in
	0|1|2|3|4|5|6|7|8|9) ;;	# valid php minor version
	*)
	echo "The '${2}' setting is not a valid PHP minor version"
	return 1
	;;
esac

get_bucket() {
	/raven/bin/ravenadm locate ${1} | awk -F"/bucket_" '{print "bucket_" $2}'
}

while read extension; do
	oldport=php84-${extension}
	newport=php${1}${2}-${extension}
	oldbucket=$(get_bucket ${oldport})
	newbucket=$(get_bucket ${newport})

	if [ -d ${RAVENSRC}/${newbucket} -a "${FORCE}" = "" ]; then
		echo "The ${newbucket} directory already exists, skipping ..."
	else
 		rm -rf ${RAVENSRC}/${newbucket}
		bucketdir=$(dirname ${newbucket})
		if [ -d ${RAVENSRC}/${bucketdir} ]; then
			mkdir -p ${RAVENSRC}/${bucketdir}
		fi
		cp -a ${RAVENSRC}/${oldbucket} ${RAVENSRC}/${newbucket}
		sed -i '' -e "s|PHP_8.4_|PHP_${1}.${2}_|" ${RAVENSRC}/${newbucket}/specification
		sed -i '' -e "s|8\.1|${1}.${2}|g" ${RAVENSRC}/${newbucket}/descriptions/*
	fi
	(cd ${RAVENSRC}/${newbucket} && \
		/raven/bin/ravenadm dev distinfo &&
		/raven/bin/ravenadm dev buildsheet . save)

done < ${LISTFILE}
