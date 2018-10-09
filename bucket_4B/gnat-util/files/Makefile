# To avoid a cirular dependency with GPRBuild, this custom BSD Makefile is
# used instead of the provided asis.gpr file.

CP=		cp -p
MKDIR=		mkdir -p
SRC=		gen_src
ADA_FLAGS=	-O2 -gnatn -gnatws -gnat05
C_FLAGS=	-O2
ADB_SRCS!=	cd ${.CURDIR} && ls *.adb | sort -r
GEN_SRCS=	sdefault.adb snames.adb xsnamest.adb
ADS_SRCS=	rident.ads hostparm.ads err_vars.ads alloc.ads
C_SRCS=		link.c osint_scars.c
LIB_SRCS+=	${C_SRCS} ${GEN_SRCS} ${ADS_SRCS} ${ADB_SRCS:Nlib-*.adb}
LIB_OBJS=	${LIB_SRCS:R:S/$/.o/}

.if ${OPSYS} == Linux || ${OPSYS} == SunOS || ${OPSYS} == Darwin
TSORT=		tsort 2>/dev/null
.else
TSORT=		tsort -q
.endif

.PHONY: all
.PHONY: generate_sources
.PHONY: libgnat-util.a
.PHONY: install
.PHONY: clean

all: libgnat-util.a

generate_sources:
	(cd ${.CURDIR} && ${MKDIR} ${SRC} lib)
	${CP} ${.CURDIR}/sdefault_adb.gnat-util ${.CURDIR}/${SRC}/sdefault.adb
	(cd ${.CURDIR} && ${CP} \
	    xsnamest.adb xutil.* snames.adb-tmpl snames.ads-tmpl \
	    snames.h-tmpl ${SRC})
	(cd ${.CURDIR}/${SRC} && \
	   gnatmake -gnatf -gnatwae -gnatyg -gnatyS xsnamest && \
	   ./xsnamest && mv snames.ns snames.ads && mv snames.nb snames.adb)

${LIB_OBJS}: generate_sources

install:
	${MKDIR} ${DESTDIR}${PREFIX}/lib/gnat
	${MKDIR} ${DESTDIR}${PREFIX}/lib/gnat-util
	${MKDIR} ${DESTDIR}${PREFIX}/include/gnat-util

	${BSD_INSTALL_DATA} ../gnat_util.gpr ${DESTDIR}${PREFIX}/lib/gnat
	find ../lib -type f -exec $(BSD_INSTALL_DATA) {} \
		${DESTDIR}${PREFIX}/lib/gnat-util \;
	find ../* -name \*\.ad\[bs\] -exec $(BSD_INSTALL_DATA) {} \
		${DESTDIR}${PREFIX}/include/gnat-util \;

clean:
	rm -f ${.OBJDIR}/*
	rm -f ${.CURDIR}/lib/*
	rm -rf ${.CURDIR}/${SRC}

.SUFFIXES: .adb .ads .c .o

.adb.o:
	ada ${ADA_FLAGS} -I../ -I../${SRC} -c ../${.TARGET:R}.adb

.c.o:
	${CC} ${C_FLAGS} -c ../${.TARGET:R}.c

${ADS_SRCS:R:S/$/.o/}:
	ada ${ADA_FLAGS} -I../${SRC} -c ../${.TARGET:R}.ads

${GEN_SRCS:R:S/$/.o/}:
	ada ${ADA_FLAGS} -I../ -c ../${SRC}/${.TARGET:R}.adb

libgnat-util.a: ${LIB_OBJS}
	ar cq ${.TARGET} `lorder ${LIB_OBJS} | ${TSORT}`
	ranlib ${.TARGET}
	mv ${.TARGET} *.ali ../lib
