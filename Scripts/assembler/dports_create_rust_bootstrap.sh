#!/bin/sh
#
# This script builds dragonfly's rust bootstrap packages from
# a dports package.  Normally they are built from Ravenports
# package using the "create_rust_bootstrap.sh" script
# It accepts two arguments
#   1) version in the format "x.yy.z".
#   2) optional: revison + epoch value
#
# The dports package should be put in the ravenports distfiles
# directory.
#
# e.g. <DISTDIR>/rust-1.41.0.txz   
# would require invocation of: dports_create_rust_bootstrap.sh 1.41.0
#
# Output: <DISTDIR>/rust-std-1.41.0-x86_64-unknown-dragonfly.tar.xz
#         <DISTDIR>/rustc-1.41.0-x86_64-unknown-dragonfly.tar.xz
#         <DISTDIR>/cargo-<calc>-x86_64-unknown-dragonfly.tar.xz
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
RPKG=${DISTDIR}/rust-${1}${REVEPOCH}.txz
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

# build rust-installer

(cd ${BBASE} && git clone https://github.com/rust-lang/rust-installer.git)
env PATH=${PATH}:${RASSY}/usr/local/bin \
    LD_LIBRARY_PATH=${RASSY}/usr/local/lib \
	cargo build \
	--manifest-path="${RINST}/Cargo.toml"

if [ $? -ne 0 ]; then
   echo "rust-installer build failed, aborting ..."
   exit 1
fi

#CARGOVER=$(awk -f ${SCRIPTSDIR}/_cargo.awk ${RASSY}/usr/local/lib/rustlib/src/rust/Cargo.lock)
CARGOVER=0.42.0
NAME_CARGO=cargo-${CARGOVER}-${DFLY}
NAME_CARGO_PKG=${NAME_CARGO}.tar.zst

# rust-std package
echo rust-std-${DFLY} > ${RASSY}/${NAME_STD}/components
cp -a ${RASSY}/usr/local/lib/rustlib/rust-installer-version ${RASSY}/${NAME_STD}/
cp -a ${RASSY}/usr/local/lib/rustlib/${DFLY}/lib ${RASSY}/${NAME_STD}/${RUSTLIB}/${DFLY}/
MANIFEST=$(cd ${RASSY}/${NAME_STD}/rust-std-${DFLY} && find -s * -type f)
for M in ${MANIFEST}; do
	echo "file:${M}" >> ${RASSY}/${NAME_STD}/rust-std-${DFLY}/manifest.in
done
${RINST}/target/debug/fabricate script \
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
mkdir -p ${RASSY}/${NAME_C}/rustc/lib/rustlib/${DFLY}/codegen-backends
echo ${1} > ${RASSY}/${NAME_C}/version
echo rustc > ${RASSY}/${NAME_C}/components
cp -a ${RASSY}/usr/local/lib/rustlib/rust-installer-version ${RASSY}/${NAME_C}/
for B in rust-gdb rust-lldb rustc rustdoc; do
  cp -a ${RASSY}/usr/local/bin/${B} ${RASSY}/${NAME_C}/rustc/bin/
done
cp -a ${RASSY}/usr/local/lib/lib* ${RASSY}/${NAME_C}/rustc/lib/
cp -a ${RASSY}/usr/local/lib/rustlib/etc/* ${RASSY}/${NAME_C}/rustc/lib/rustlib/etc/
MANIFEST=$(cd ${RASSY}/${NAME_C}/rustc && find -s * -type f)
for M in ${MANIFEST}; do
	echo "file:${M}" >> ${RASSY}/${NAME_C}/rustc/manifest.in
done
${RINST}/target/debug/fabricate script \
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
cp -a ${RASSY}/usr/local/lib/rustlib/rust-installer-version ${RASSY}/${NAME_CARGO}/
cp -a ${RASSY}/usr/local/bin/cargo ${RASSY}/${NAME_CARGO}/cargo/bin/
cp -a ${RASSY}/usr/local/share/zsh/site-functions/_cargo ${RASSY}/${NAME_CARGO}/cargo/share/zsh/site-functions
MANIFEST=$(cd ${RASSY}/${NAME_CARGO}/cargo && find -s * -type f)
for M in ${MANIFEST}; do
	echo "file:${M}" >> ${RASSY}/${NAME_CARGO}/cargo/manifest.in
done
${RINST}/target/debug/fabricate script \
	--product-name=Rust \
	--rel-manifest-dir=rustlib \
	--success-message=Cargo-is-cool-to-cruise. \
	--output-script=${RASSY}/${NAME_CARGO}/install.sh \
	--legacy-manifest-dirs="rustlib,cargo"
rm -f ${DISTDIR}/${NAME_CARGO_PKG}
echo "Creating and relocating ${NAME_CARGO_PKG}."
(cd ${RASSY} && ${MYTAR} -c --zstd -f ${NAME_CARGO_PKG} ${NAME_CARGO}) && mv ${RASSY}/${NAME_CARGO_PKG} ${DISTDIR}/

echo "cleaning everything up."
# rm -rf ${RASSY} ${RINST}
