# Relocate official toolchain

all: toolchain

toolchain:
	@echo "building not required"

install:
	mkdir -p ${DESTDIR}${PREFIX}/share
	cp /packages/All/gcc6-*-${COMPVER}.txz ${DESTDIR}${PREFIX}/share/
	# In bulk run, ravensys-tool fails frequently because multiple ports
	# are accessing gcc at the same time.  Move copy to tarballs first, and then
	# extract those copies to avoid this issue.
.for spkg in compilers ada_run cxx_run fortran_run libs
	tar -xf ${DESTDIR}${PREFIX}/share/gcc6-${spkg}-standard-${COMPVER}.txz ${LOCALBASE}
.endfor
	tar -xf /packages/All/binutils-single-ravensys-*.txz ${LOCALBASE}

	cp -a ${LOCALBASE:T}/toolchain/bin  ${DESTDIR}${PREFIX}/
	cp -a ${LOCALBASE:T}/toolchain/lib  ${DESTDIR}${PREFIX}/
	cp -a ${LOCALBASE:T}/toolchain/gcc6 ${DESTDIR}${PREFIX}/
	rm -rf ${DESTDIR}${PREFIX}/gcc6/share/licenses
