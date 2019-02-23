# $FreeBSD: head/lib/libfetch/Makefile 275024 2014-11-25 11:07:26Z bapt $

SRCS=		fetch.c common.c ftp.c http.c file.c ftperr.h httperr.h
CSRC=		${SRCS:M*.c}
OBJS=		${CSRC:.c=.o}
PREFIX?=	/usr/local
CFLAGS=		-DINET6 -DWITH_SSL -DFTP_COMBINE_CWDS
CFLAGS+=	-I${PREFIX}/libressl/include
CFLAGS+=	-I${PREFIX}/include -I.
LIBS=		${PREFIX}/libressl/lib/libssl.a \
		${PREFIX}/libressl/lib/libcrypto.a \

.if "${OPSYS}" == "Linux"
LIBS+=		${PREFIX}/lib/libbsd.a
LDFLAGS+=	-lpthread
.endif

.if "${OPSYS}" == "SunOS"
LIBS+=		${PREFIX}/lib/libbsd.a
CFLAGS+=	-I${PREFIX}/include/bsd
LDFLAGS+=	-lresolv -lsocket
.endif

all: fetch

clean:
	rm -f ${OBJS} fetch

${OBJS}: ${.TARGET:.o=.c}
	${CC} -c ${.ALLSRC} ${CFLAGS}

fetch:	${OBJS} main.c
	${CC} -o fetch main.c ${OBJS} ${CFLAGS} ${LIBS} ${LDFLAGS}

install:
	${BSD_INSTALL_PROGRAM} fetch ${DESTDIR}${PREFIX}/bin/
