# Relocate official toolchain

all: toolchain

toolchain:
	@echo "building not required"

TARGS=	--no-same-permissions
ALPHA=	ravensys-gcc
ATAIL=	standard-${COMPVER}
BRAVO=	ravensys-binutils-single-standard-${BUVER}

install:
	mkdir -p ${DESTDIR}${PREFIX}/share
	cp /packages/All/${ALPHA}-*-${COMPVER}.tzst ${DESTDIR}${PREFIX}/share/
	cp /packages/All/${BRAVO}.tzst ${DESTDIR}${PREFIX}/share/
	# In bulk run, ravensys-tool fails frequently during tar -xf, but the
	# reason is unclear.  In addition to copying gcc tarballs first, make
	# tarball extraction occur after dedicated decompression to try to
	# fix this.  Memory issue?  only occurs during full load.
.for spkg in compilers ada_run cxx_run fortran_run libs
	cp /packages/All/${ALPHA}-${spkg}-${ATAIL}.tzst \
		/tmp/${ALPHA}-${spkg}-${ATAIL}.tar.zst
	zstd -d -q /tmp/${ALPHA}-${spkg}-${ATAIL}.tar.zst
	tar -xf /tmp/${ALPHA}-${spkg}-${ATAIL}.tar ${TARGS}
.endfor
	cp /packages/All/${BRAVO}.tzst /tmp/${BRAVO}.tar.zst
	zstd -d -q /tmp/${BRAVO}.tar.zst
	tar ${TARGS} -xf /tmp/${BRAVO}.tar ${LOCALBASE} 

	cp -a ${LOCALBASE:T}/toolchain/bin          ${DESTDIR}${PREFIX}/
	cp -a ${LOCALBASE:T}/toolchain/lib          ${DESTDIR}${PREFIX}/
	cp -a ${LOCALBASE:T}/toolchain/include      ${DESTDIR}${PREFIX}/
	cp -a ${LOCALBASE:T}/toolchain/ravensys-gcc ${DESTDIR}${PREFIX}/
	rm -rf ${DESTDIR}${PREFIX}/ravensys-gcc/share/licenses
	# create dangling symlinks to ld.mold and ld.lld
	ln -s ../../bin/mold ${DESTDIR}${PREFIX}/bin/ld.mold
	ln -s ../../bin/lld  ${DESTDIR}${PREFIX}/bin/ld.lld

.if "${OPSYS}" == "SunOS"
	rm ${DESTDIR}${PREFIX}/bin/ld
	cp ${LOCALBASE}/libexec/ld ${DESTDIR}${PREFIX}/bin/
	cp /usr/bin/ld.sun ${DESTDIR}${PREFIX}/bin/
	(cd ../ravensys-toolchain_1${LOCALBASE}/bin/ && \
	 cp -a lld ld.lld ld64.lld ${DESTDIR}${PREFIX}/bin/)
.endif
