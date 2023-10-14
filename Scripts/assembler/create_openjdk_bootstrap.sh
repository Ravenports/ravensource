#!/bin/sh
#
# This script build a bootstrap package for a specific version of OpenJDK
# and specific to the the platform that the package is built on.
# It accepts three arguments:
#   1) Version in the format "x.yy.z
#   2) optional: revision + epoch value
#
# These value correspond to the latest version of OpenJDK in the repository.
#
# e.g. <DISTDIR>/openjdk18-primary-standard-18.0.2_1.tzst
# would require invocation of: create_openjdk_bootstrap.sh 18.0.2 1
#
# Output: <DISTDIR}/bootstrap-openjdk-18.0.2-dragonfly-x86_64.tzst (dragonfly)
#         <DISTDIR}/bootstrap-openjdk-18.0.2-freebsd-amd64.tzst    (freebsd)

if [ $# -lt 1 ]; then
   echo "Usage: $0 openjdk_version <revision,epoch>"
   exit 0
fi
REVEPOCH=
if [ $# -ge 2 ]; then
   REVEPOCH=_$2
fi

THISDIR=$(dirname $0)
SCRIPTSDIR=$(cd ${THISDIR} && pwd -P)
DISTDIR=$(/raven/bin/ravenadm dev info F)
BBASE=$(/raven/bin/ravenadm dev info J)
PKGDIR=$(/raven/bin/ravenadm dev info H)/All
ASSY="${BBASE}/openjdk-assy"
OPSYS=$(uname -s)
MYTAR="/raven/share/raven/sysroot/${OPSYS}/usr/bin/tar"
MAJOR=$(echo "${1}" | awk -F'.' '{print $1}')
RPKG="${PKGDIR}/openjdk${MAJOR}-primary-standard-${1}${REVEPOCH}.tzst"

rm -rf ${ASSY}

if [ ! -f ${RPKG} ]; then
   echo "Package not found: ${RPKG}"
   exit 1
fi

TARGET=$(/raven/sbin/ravensw info -F "${RPKG}" | awk '/^Architecture/ {n=split($3,t,":"); arch = length(t) == 4 ? t[3] "_" t[4] : t[3]; print t[1] "-" arch}')
TPKG="bootstrap-openjdk-${1}-${TARGET}.tzst"

mkdir -p ${ASSY}
echo "Extracting ${RPKG} ..."
(cd ${ASSY} && ${MYTAR} -xf ${RPKG})
echo "Bootstrap javac at ${ASSY}/raven/openjdk${MAJOR}/bin"
sleep 2

rm -f ${DISTDIR}/${RPKG}
echo "Creating and relocating ${TPKG} to ${DISTDIR} directory"
(cd ${ASSY}/raven && ${MYTAR} -c --zstd -f ${TPKG} openjdk${MAJOR}) && \
mv ${ASSY}/raven/${TPKG} ${DISTDIR}/
