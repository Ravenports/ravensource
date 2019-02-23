# $FreeBSD: src/lib/libmd/Makefile,v 1.42 2005/03/09 19:23:04 cperciva Exp $

SRCS=		md5c.c md5hl.c sha256hl.c
OBJS=		${SRCS:.c=.o}
PREFIX?=	/usr/local
LIBS=		${PREFIX}/libressl/lib/libcrypto.a
CFLAGS=		-I${PREFIX}/libressl/include
CFLAGS+=	-I${PREFIX}/include -I.	

.if "${OPSYS}" == "Linux"
LIBS+=		${PREFIX}/lib/libbsd.a
.endif
.if "${OPSYS}" == "SunOS"
LIBS+=		${PREFIX}/lib/libbsd.a
CFLAGS+=	-I${PREFIX}/include/bsd
.endif

all:	program

${OBJS}: ${.TARGET:.o=.c}
	${CC} -c ${.ALLSRC} ${CFLAGS}

md5hl.c: mdXhl.c
	(echo '#define LENGTH 16'; \
		sed -e 's/mdX/md5/g' -e 's/MDX/MD5/g' ${.ALLSRC}) > ${.TARGET}

sha256hl.c: mdXhl.c
	(echo '#define LENGTH 32'; \
		sed -e 's/mdX/sha256/g' -e 's/MDX/SHA256_/g'	\
			-e  's/SHA256__/SHA256_/g' \
		${.ALLSRC}) > ${.TARGET}

program: ${OBJS} main.c
	${CC} -o md5 main.c ${OBJS} ${CFLAGS} ${LIBS}
	ln md5 sha256

install:
	${BSD_INSTALL_PROGRAM} md5 ${DESTDIR}${PREFIX}/bin/
	${BSD_INSTALL_PROGRAM} sha256 ${DESTDIR}${PREFIX}/bin/

clean:
	rm -f md5hl.c sha256hl.c md5 sha256 ${OBJS}
