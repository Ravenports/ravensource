PROG=		which
SRCS=		${PROG}.c
PREFIX?=	/usr/local
CFLAGS+=	-I.
STATIC_LIBS=	

.if "${OPSYS}" == "SunOS" || "${OPSYS}" == "Linux"
STATIC_LIBS+=	${PREFIX}/lib/libbsd.a
CFLAGS+=	-DLIBBSD_OVERLAY -I${PREFIX}/include/bsd
.endif


all: ${PROG}

clean:
	rm -f ${OBJS} ${PROG}

${PROG}: ${SRCS}
	${CC} -o ${PROG} ${.ALLSRC} ${CFLAGS} ${STATIC_LIBS}

install:
	${BSD_INSTALL_PROGRAM} ${PROG} ${DESTDIR}${PREFIX}/bin/
	${BSD_INSTALL_MAN} ${PROG}.1 ${DESTDIR}${PREFIX}/share/man/man1
