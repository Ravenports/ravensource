PROG=		makewhatis
SRCS=		${PROG}.c
PREFIX?=	/usr/local
CFLAGS+=	-I${PREFIX}/include -I.
STATIC_LIBS=	${PREFIX}/lib/libz.a

.if "${OPSYS}" == "Linux"
STATIC_LIBS+=	${PREFIX}/lib/libbsd.a
.endif


all: ${PROG}

clean:
	rm -f ${OBJS} makewhatis

${PROG}: ${SRCS}
	${CC} -o ${PROG} ${.ALLSRC} ${CFLAGS} ${STATIC_LIBS}

install:
	${BSD_INSTALL_PROGRAM} ${PROG} ${DESTDIR}${PREFIX}/bin/
	${BSD_INSTALL_MAN} ${PROG}.8 ${DESTDIR}${PREFIX}/share/man/man8
