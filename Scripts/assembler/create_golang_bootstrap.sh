#!/bin/sh
#
# This script build a bootstrap package for a specific version of Go
# and specific to the the platform that the package is built on.
# It accepts three arguments:
#   1) Version in the format "x.yy.z
#   2) optional: revision + epoch value
#
# These value correspond to the packaged version of Go that will be
# repackaged as a bootstrap compiler.
#
# e.g. <DISTDIR>/golang-single-standard-1.22.2.tzst
# would require invocation of: create_golang_bootstrap.sh 1.22.2
#
# Output: <DISTDIR}/bootstrap-golang-1.22.2-dragonfly-x86_64.tzst (dragonfly)
#         <DISTDIR}/bootstrap-golang-1.22.2-freebsd-amd64.tzst    (freebsd)

if [ $# -lt 1 ]; then
   echo "Usage: $0 golang_version <revision,epoch>"
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
ASSY="${BBASE}/golang-assy"
OPSYS=$(uname -s)
MYTAR="/raven/share/raven/sysroot/${OPSYS}/usr/bin/tar"
RPKG="${PKGDIR}/golang-single-standard-${1}${REVEPOCH}.tzst"

rm -rf ${ASSY}

if [ ! -f ${RPKG} ]; then
   echo "Package not found: ${RPKG}"
   exit 1
fi

TARGET=$(/raven/sbin/ravensw info -F "${RPKG}" | awk '/^Architecture/ {n=split($3,t,":"); arch = length(t) == 4 ? t[3] "_" t[4] : t[3]; print t[1] "-" arch}')
TPKG="bootstrap-golang-${1}-${TARGET}.tzst"

mkdir -p ${ASSY}
echo "Extracting ${RPKG} ..."
(cd ${ASSY} && ${MYTAR} -xf ${RPKG})
echo "Bootstrap Go at ${ASSY}/raven"
# remove documentation
rm -rf ${ASSY}/raven/go/api
rm -rf ${ASSY}/raven/go/doc
rm ${ASSY}/raven/go/CONTRIBUTING.md
rm ${ASSY}/raven/go/LICENSE
rm ${ASSY}/raven/go/PATENTS
rm ${ASSY}/raven/go/SECURITY.md
find ${ASSY}/raven/go \( -name "*.html" -o -name "*.css" -o -name "*.js" -o -name "*.png" -o -name "README*" \) -delete
sleep 2

rm -f ${DISTDIR}/${RPKG}
echo "Creating and relocating ${TPKG} to ${DISTDIR} directory"
(cd ${ASSY}/raven && ${MYTAR} -c --zstd -f ${TPKG} bin go) && \
mv ${ASSY}/raven/${TPKG} ${DISTDIR}/

echo "cleaning everything up."
rm -rf ${RASSY}
