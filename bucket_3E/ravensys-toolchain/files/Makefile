# Relocate official toolchain

all: toolchain

toolchain:
	@echo "building not required"

install:
	mkdir -p ${DESTDIR}${PREFIX}/share
	cp /packages/All/${GCCX}-*-${COMPVER}.tzst ${DESTDIR}${PREFIX}/share/
	cp /packages/All/binutils-single-ravensys-${BUVER}.tzst ${DESTDIR}${PREFIX}/share/
	# In bulk run, ravensys-tool fails frequently during tar -xf, but the
	# reason is unclear.  In addition to copying gcc tarballs first, make
	# tarball extraction occur after dedicated decompression to try to
	# fix this.  Memory issue?  only occurs during full load.
.for spkg in compilers ada_run cxx_run fortran_run libs
	cp /packages/All/${GCCX}-${spkg}-standard-${COMPVER}.tzst \
		/tmp/${GCCX}-${spkg}-standard-${COMPVER}.tar.zst
	zstd -d -q /tmp/${GCCX}-${spkg}-standard-${COMPVER}.tar.zst
	tar -xf /tmp/${GCCX}-${spkg}-standard-${COMPVER}.tar
.endfor
	cp /packages/All/binutils-single-ravensys-${BUVER}.tzst \
		/tmp/binutils-single-ravensys-${BUVER}.tar.zst
	zstd -d -q /tmp/binutils-single-ravensys-${BUVER}.tar.zst
	tar -xf /tmp/binutils-single-ravensys-${BUVER}.tar ${LOCALBASE}

	cp -a ${LOCALBASE:T}/toolchain/bin     ${DESTDIR}${PREFIX}/
	cp -a ${LOCALBASE:T}/toolchain/lib     ${DESTDIR}${PREFIX}/
	cp -a ${LOCALBASE:T}/toolchain/${GCCX} ${DESTDIR}${PREFIX}/
	cp -a ${LOCALBASE:T}/toolchain/include ${DESTDIR}${PREFIX}/
	rm -rf ${DESTDIR}${PREFIX}/${GCCX}/share/licenses
