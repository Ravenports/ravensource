#!/bin/sh
#
# This script builds dragonfly's rust bootstrap packages.
# It accepts two arguments
#   1) version in the format "x.yy.z".
#   2) optional: revison + epoch value
#
# This is the current version of rust in the ravenports repository, and
# the corresponding package is considered to already be built.
#
# e.g. <DISTDIR>/rust-single-standard-1.32.0_1.tzst
# would require invocation of: create_rust_bootstrap.sh 1.32.0 1
#
# Output: <DISTDIR>/rust-std-1.32.0-x86_64-unknown-dragonfly.tar.zst
#         <DISTDIR>/rustc-1.32.0-x86_64-unknown-dragonfly.tar.zst
#         <DISTDIR>/cargo-<calc>-x86_64-unknown-dragonfly.tar.zst
#
# requires installation:
#   libexecinfo-single-standard
#   ravensys-gcc-complete-standard

if [ $# -lt 1 ]; then
   echo "Usage: $0 rust_version <revision,epoch>"
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
RASSY=${BBASE}/rust-assy
RINST=${BBASE}/rust-installer
RPKG=${PKGDIR}/rust-single-standard-${1}${REVEPOCH}.tzst
MYTAR=/raven/share/raven/sysroot/DragonFly/usr/bin/tar
DFLY=x86_64-unknown-dragonfly
NAME_STD=rust-std-${1}-${DFLY}
NAME_STD_PKG=${NAME_STD}.tar.zst
NAME_C=rustc-${1}-${DFLY}
NAME_C_PKG=${NAME_C}.tar.zst
RUSTLIB=rust-std-${DFLY}/lib/rustlib

rm -rf ${RASSY} ${RINST}

if [ ! -f ${RPKG} ]; then
   echo "Package not found: ${RPKG}"
   exit 1
fi

mkdir -p ${RASSY}/${NAME_STD}/${RUSTLIB}/${DFLY}
echo "Extracting ${RPKG} ..."
(cd ${RASSY} && ${MYTAR} -xf ${RPKG})
echo "Bootstrap rust at ${RASSY}/raven/bin"
sleep 2

# build rust-installer

(cd ${BBASE} && git clone https://github.com/rust-lang/rust-installer.git)
# env PATH=${PATH}:${RASSY}/raven/bin CARGO_HTTP_CAINFO=/raven/share/certs/ca-root-nss.crt \
#   cargo build --manifest-path="${RINST}/Cargo.toml"
env PATH=${PATH}:${RASSY}/raven/bin cargo build --manifest-path="${RINST}/Cargo.toml"

if [ $? -ne 0 ]; then
   echo "rust-installer build failed, aborting ..."
   exit 1
fi

# CARGOVER is obsolete, cargo now has same version as the other packages
# CARGOVER=$(awk -f ${SCRIPTSDIR}/_cargo.awk ${RASSY}/raven/lib/rustlib/src/rust/Cargo.lock)
# NAME_CARGO=cargo-${CARGOVER}-${DFLY}
NAME_CARGO=cargo-${1}-${DFLY}
NAME_CARGO_PKG=${NAME_CARGO}.tar.zst

# rust-std package
echo rust-std-${DFLY} > ${RASSY}/${NAME_STD}/components
cp -a ${RASSY}/raven/lib/rustlib/rust-installer-version ${RASSY}/${NAME_STD}/
cp -a ${RASSY}/raven/lib/rustlib/${DFLY}/lib ${RASSY}/${NAME_STD}/${RUSTLIB}/${DFLY}/
MANIFEST=$(cd ${RASSY}/${NAME_STD}/rust-std-${DFLY} && find -s * -type f)
for M in ${MANIFEST}; do
	echo "file:${M}" >> ${RASSY}/${NAME_STD}/rust-std-${DFLY}/manifest.in
done
${RINST}/target/debug/rust-installer script \
	--product-name=Rust \
	--rel-manifest-dir=rustlib \
	--success-message=std-is-standing-at-the-ready. \
	--output-script=${RASSY}/${NAME_STD}/install.sh \
	--legacy-manifest-dirs="rustlib,cargo"
rm -f ${DISTDIR}/${NAME_STD_PKG}
echo "Creating and relocating ${NAME_STD_PKG}."
(cd ${RASSY} && ${MYTAR} -c --zstd -f ${NAME_STD_PKG} ${NAME_STD}) && mv ${RASSY}/${NAME_STD_PKG} ${DISTDIR}/

# rustc package
mkdir -p ${RASSY}/${NAME_C}/rustc/bin
mkdir -p ${RASSY}/${NAME_C}/rustc/lib/rustlib/etc
echo ${1} > ${RASSY}/${NAME_C}/version
echo rustc > ${RASSY}/${NAME_C}/components
cp -a ${RASSY}/raven/lib/rustlib/rust-installer-version ${RASSY}/${NAME_C}/
for B in rust-gdb rust-lldb rustc rustdoc; do
  cp -a ${RASSY}/raven/bin/${B} ${RASSY}/${NAME_C}/rustc/bin/
done
cp -a ${RASSY}/raven/lib/lib* ${RASSY}/${NAME_C}/rustc/lib/
cp -a ${RASSY}/raven/lib/rustlib/etc/* ${RASSY}/${NAME_C}/rustc/lib/rustlib/etc/
MANIFEST=$(cd ${RASSY}/${NAME_C}/rustc && find -s * -type f)
for M in ${MANIFEST}; do
	echo "file:${M}" >> ${RASSY}/${NAME_C}/rustc/manifest.in
done
${RINST}/target/debug/rust-installer script \
	--product-name=Rust \
	--rel-manifest-dir=rustlib \
	--success-message=Rust-is-ready-to-roll. \
	--output-script=${RASSY}/${NAME_C}/install.sh \
	--legacy-manifest-dirs="rustlib,cargo"
rm -f ${DISTDIR}/${NAME_C_PKG}
echo "Creating and relocating ${NAME_C_PKG}."
(cd ${RASSY} && ${MYTAR} -c --zstd -f ${NAME_C_PKG} ${NAME_C}) && mv ${RASSY}/${NAME_C_PKG} ${DISTDIR}/

#cargo package
mkdir -p ${RASSY}/${NAME_CARGO}/cargo/bin
mkdir -p ${RASSY}/${NAME_CARGO}/cargo/share/zsh/site-functions
echo ${CARGOVER} > ${RASSY}/${NAME_CARGO}/version
echo cargo > ${RASSY}/${NAME_CARGO}/components
cp -a ${RASSY}/raven/lib/rustlib/rust-installer-version ${RASSY}/${NAME_CARGO}/
cp -a ${RASSY}/raven/bin/cargo ${RASSY}/${NAME_CARGO}/cargo/bin/
cp -a ${RASSY}/raven/share/zsh/site-functions/_cargo ${RASSY}/${NAME_CARGO}/cargo/share/zsh/site-functions
MANIFEST=$(cd ${RASSY}/${NAME_CARGO}/cargo && find -s * -type f)
for M in ${MANIFEST}; do
	echo "file:${M}" >> ${RASSY}/${NAME_CARGO}/cargo/manifest.in
done
${RINST}/target/debug/rust-installer script \
	--product-name=Rust \
	--rel-manifest-dir=rustlib \
	--success-message=Cargo-is-cool-to-cruise. \
	--output-script=${RASSY}/${NAME_CARGO}/install.sh \
	--legacy-manifest-dirs="rustlib,cargo"
rm -f ${DISTDIR}/${NAME_CARGO_PKG}
echo "Creating and relocating ${NAME_CARGO_PKG}."
(cd ${RASSY} && ${MYTAR} -c --zstd -f ${NAME_CARGO_PKG} ${NAME_CARGO}) && mv ${RASSY}/${NAME_CARGO_PKG} ${DISTDIR}/

echo "cleaning everything up."
rm -rf ${RASSY} ${RINST}
