#!/bin/sh
#
# This script build a bootstrap package for a specific version of SBCL
# and specific to the the platform that the package is built on.
# It accepts three arguments:
#   1) Version in the format "x.yy.z
#   2) optional: revision + epoch value
#
# These value correspond to the packaged version of SBCL that will be
# repackaged as a bootstrap compiler.
#
# e.g. <DISTDIR>/sbcl~primary~std~2.4.8.rvn
# would require invocation of: create_sbcl_bootstrap.sh 2.4.8
#
# Output: <DISTDIR}/bootstrap-sbcl-2.4.8-dragonfly-x86_64.tzst (dragonfly)
#         <DISTDIR}/bootstrap-sbcl-2.4.8-freebsd-amd64.tzst    (freebsd)

if [ $# -lt 1 ]; then
   echo "Usage: $0 sbcl_version <revision,epoch>"
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
ASSY="${BBASE}/sbcl-assy"
OPSYS=$(uname -s)
MYTAR="/raven/share/raven/sysroot/${OPSYS}/usr/bin/tar"
RPKG="${PKGDIR}/sbcl~primary~std~${1}${REVEPOCH}.rvn"

rm -rf ${ASSY}

if [ ! -f ${RPKG} ]; then
   echo "Package not found: ${RPKG}"
   exit 1
fi

TARGET=$(/raven/sbin/rvn info -F "${RPKG}" | awk '/^abi/ {n=split($3,t,":"); print t[1] "-" t[2]}')
TPKG="bootstrap-sbcl-${1}-${TARGET}.tzst"

mkdir -p ${ASSY}
echo "Extracting ${RPKG} ..."
xrvn -o ${ASSY} -x ${RPKG}
echo "Bootstrap SBCL at ${ASSY}/raven"
# remove man page
rm -rf ${ASSY}/raven/share/man
rm -rf ${ASSY}/raven/etc
sleep 2

rm -f ${DISTDIR}/${RPKG}
echo "Creating and relocating ${TPKG} to ${DISTDIR} directory"
mv ${ASSY}/raven ${ASSY}/bootstrap
(cd ${ASSY} && ${MYTAR} -c --zstd -f ${TPKG} bootstrap) && \
mv ${ASSY}/${TPKG} ${DISTDIR}/

echo "cleaning everything up."
rm -rf ${RASSY}
