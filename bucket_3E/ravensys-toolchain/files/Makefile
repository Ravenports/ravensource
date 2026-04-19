# Relocate official toolchain

all: toolchain

toolchain:
	@echo "building not required"

ALPHA=	ravensys-gcc
ATAIL=	std~${COMPVER}
BRAVO=	ravensys-binutils~single~std~${BUVER}

install:
	mkdir -p ${DESTDIR}${PREFIX}/share
	cp /repo/files/${ALPHA}~*~${COMPVER}.rvn ${DESTDIR}${PREFIX}/share/
	cp /repo/files/${BRAVO}.rvn ${DESTDIR}${PREFIX}/share/

.for spkg in compilers ada_run cxx_run fortran_run libs
	xrvn -x -o /tmp /repo/files/${ALPHA}~${spkg}~${ATAIL}.rvn
.endfor
	xrvn -x -o /tmp /repo/files/${BRAVO}.rvn

	cp -a /tmp/raven/toolchain/bin          ${DESTDIR}${PREFIX}/
	cp -a /tmp/raven/toolchain/lib          ${DESTDIR}${PREFIX}/
	cp -a /tmp/raven/toolchain/include      ${DESTDIR}${PREFIX}/
	cp -a /tmp/raven/toolchain/ravensys-gcc ${DESTDIR}${PREFIX}/
	rm -rf ${DESTDIR}${PREFIX}/ravensys-gcc/share/licenses

	rm ${DESTDIR}${PREFIX}/bin/ld
.if "${OPSYS}" == "SunOS"
	cp /usr/bin/ld.sun ${DESTDIR}${PREFIX}/bin/ld
.else
	cp ${LOCALBASE}/libexec/ld ${DESTDIR}${PREFIX}/bin/ld
	mkdir -p ${DESTDIR}${PREFIX}/llvm/bin
	mkdir -p ${DESTDIR}${PREFIX}/llvm/lib
	cp ${LOCALBASE}/bin/ld.lld ${DESTDIR}${PREFIX}/llvm/bin/
	cp ${LOCALBASE}/lib/libLLVM.so.${LMAJMIN} ${DESTDIR}${PREFIX}/llvm/lib/
.endif
