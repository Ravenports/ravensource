# $FreeBSD: head/lib/libfetch/Makefile 275024 2014-11-25 11:07:26Z bapt $

SRCS=		fetch.c common.c ftp.c http.c file.c ftperr.h httperr.h
CSRC=		${SRCS:M*.c}
OBJS=		${CSRC:.c=.o}
SOBJS=		${CSRC:.c=.So}
PREFIX?=	/usr/local
CFLAGS=		-DINET6 -DWITH_SSL -DFTP_COMBINE_CWDS
CFLAGS+=	-I${PREFIX}/libressl/include
CFLAGS+=	-I${PREFIX}/include -I.
LIBS=		${PREFIX}/libressl/lib/libssl.a \
		${PREFIX}/libressl/lib/libcrypto.a
LDADD=		-lssl -lcrypto
LDFLAGS=	-L${PREFIX}/libressl/lib \
		-Wl,-rpath,${PREFIX}/libressl/lib

PICFLAG=	-fpic
LIB=		fetch
LIB_MAJOR?=	1	# currently so.4 on DF and so.6 on FreeBSD
LIB_SHARED=	lib${LIB}.so.${LIB_MAJOR}
LIB_LINK=	lib${LIB}.so

.SUFFIXES:	.o .c
.SUFFIXES:	.So .c

.if "${OPSYS}" == "Linux"
LIBS+=		${PREFIX}/lib/libbsd.a
LDFLAGS+=	-lpthread
TSORT=		tsort 2>/dev/null
.elif "${OPSYS}" == "SunOS"
LIBS+=		${PREFIX}/lib/libbsd.a
CFLAGS+=	-I${PREFIX}/include/bsd
LDFLAGS+=	-lresolv -lsocket
TSORT=		tsort 2>/dev/null
.else
TSORT=		tsort -q
.endif

all: fetch

library: ${LIB_SHARED}

clean:
	rm -f ${OBJS} fetch

.c.o:
	${CC} -c ${.IMPSRC} ${CFLAGS} -o ${.TARGET}

.c.So:
	${CC} ${PICFLAG} -DPIC ${CFLAGS} -c ${.IMPSRC} -o ${.TARGET}

fetch:	${OBJS} main.c
	${CC} -o fetch main.c ${OBJS} ${CFLAGS} ${LIBS} ${LDFLAGS}

${LIB_SHARED}: ${SOBJS}
	@${ECHO} building shared ${LIB} library
	${CC_LINK} ${LDFLAGS} -shared \
	    -o ${.TARGET} -Wl,-soname,${.TARGET} \
	    `lorder ${SOBJS} | ${TSORT}` ${LDADD}

install:
	${BSD_INSTALL_PROGRAM} fetch ${DESTDIR}${PREFIX}/bin/

install-library:
	${BSD_INSTALL_LIB} ${LIB_SHARED} ${DESTDIR}${PREFIX}/lib
	ln -s ${LIB_SHARED} ${DESTDIR}${PREFIX}/lib/${LIB_LINK}
	${BSD_INSTALL_DATA} fetch.h ${DESTDIR}${PREFIX}/include
