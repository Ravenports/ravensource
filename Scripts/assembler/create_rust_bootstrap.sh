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
# e.g. <DISTDIR>/rust-single-standard-1.99.1_1.tzst
# would require invocation of: create_rust_bootstrap.sh 1.99.1 1
#
# Output: <DISTDIR>/rust-std-1.99.1-x86_64-unknown-dragonfly.tar.zst
#         <DISTDIR>/rustc-1.99.1-x86_64-unknown-dragonfly.tar.zst
#         <DISTDIR>/rustc-dev-1.99.1-x86_64-unknown-dragonfly.tar.zst
#         <DISTDIR>/cargo-1.99.1-x86_64-unknown-dragonfly.tar.zst
#
# requires installation:
#   libexecinfo-single-std
#   ravensys-gcc-set-std

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
PKGDIR=$(/raven/bin/ravenadm dev info H)/files
RASSY=${BBASE}/rust-assy
RINST=${BBASE}/rust-installer
RPKG=${PKGDIR}/rust~single~std~${1}${REVEPOCH}.rvn
MYTAR=/raven/share/raven/sysroot/DragonFly/usr/bin/tar
DFLY=x86_64-unknown-dragonfly

transfer() (
    if [ "$#" -ne 3 ]; then
        printf 'Usage: transfer manifest origin destdir\n' >&2
        exit 2
    fi

    origin=${2%/}
    destdir=${3%/}
    previous_dir=

    while IFS= read -r line || [ -n "$line" ]; do
        case "$line" in
            file:/*) path=${line#file:} ;;
            *)
                printf 'transfer: invalid manifest entry: %s\n' "$line" >&2
                exit 1
                ;;
        esac

	relative=${path#/}             # Strip the leading slash
	dest=$destdir/${relative#*/}   # Strip the first directory component
        dir=${dest%/*}

        if [ "$dir" != "$previous_dir" ]; then
            mkdir -p -- "$dir" || exit
            previous_dir=$dir
        fi

        cp -a -- "$origin$path" "$dest" || exit
    done < "$1"
)

rm -rf ${RASSY} ${RINST}

if [ ! -f ${RPKG} ]; then
   echo "Package not found: ${RPKG}"
   exit 1
fi

mkdir -p "${RASSY}/"
echo "Extracting ${RPKG} ..."
/raven/bin/xrvn -x -o "${RASSY}" "${RPKG}"
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

for spkg in cargo rustc rustc-dev rust-std
do
   name=${spkg}-${1}-${DFLY}
   name_pkg=${name}.tar.zst
   if [ "${spkg}" = "rust-std" ]; then
      manifest="${spkg}-${DFLY}"
   else
      manifest="${spkg}"
   fi
   mkdir -p "${RASSY}/${name}/${manifest}"
   echo "${1}" > "${RASSY}/${name}/version"
   echo "${manifest}" > "${RASSY}/${name}/components"
   cp -a "${RASSY}/raven/lib/rustlib/rust-installer-version" "${RASSY}/${name}/"
   cp -a "${RASSY}/raven/lib/rustlib/manifest-${manifest}"  "${RASSY}/${name}/${manifest}/manifest.in"
   transfer "${RASSY}/raven/lib/rustlib/manifest-${manifest}" "${RASSY}" "${RASSY}/${name}"
   ${RINST}/target/debug/rust-installer script \
	--product-name=Rust \
	--rel-manifest-dir=rustlib \
	--success-message="${name}-subpackage-ready." \
	--output-script="${RASSY}/${name}/install.sh" \
	--legacy-manifest-dirs="rustlib,cargo"
   rm -f "${DISTDIR}/${name_pkg}"
   echo "Creating and relocating ${name_pkg}."
   (cd "${RASSY}" && "${MYTAR}" -c --zstd -f ${name_pkg} ${name}) && mv "${RASSY}/${name_pkg}" "${DISTDIR}/"
done

echo "cleaning everything up."
rm -rf ${RASSY} ${RINST}
