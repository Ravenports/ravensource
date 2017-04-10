# Relocate official toolchain

all: toolchain

toolchain:
	@echo "building not required"

install:
	mkdir -p ${DESTDIR}${PREFIX}/share
.for spkg in compilers ada_run cxx_run fortran_run libs
	tar -xf /packages/All/gcc6-${spkg}-standard-${COMPVER}.txz ${LOCALBASE}
.endfor
	tar -xf /packages/All/binutils-single-ravensys-*.txz ${LOCALBASE}

	cp -a ${LOCALBASE:T}/toolchain/bin  ${DESTDIR}${PREFIX}/
	cp -a ${LOCALBASE:T}/toolchain/gcc6 ${DESTDIR}${PREFIX}/
	rm -rf ${DESTDIR}${PREFIX}/gcc6/share/licenses
	cp /packages/All/gcc6-*-${COMPVER}.txz ${DESTDIR}${PREFIX}/share/
