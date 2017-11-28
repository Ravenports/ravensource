PROG=		patch
SRCS=		${PROG}.c pch.c inp.c util.c backupfile.c mkpath.c \
		linux_support.c
PREFIX?=	/usr/local
CFLAGS+=	-I${PREFIX}/include -I.
STATIC_LIBS=	

.if "${OPSYS}" == "Linux" || "${OPSYS}" == "SunOS"
STATIC_LIBS+=	${PREFIX}/lib/libbsd.a
CFLAGS+=	-I${PREFIX}/include/bsd
.endif

all: ${PROG}

clean:
	rm -f ${OBJS} ${PROG}

${PROG}: ${SRCS}
	${CC} -o ${PROG} ${.ALLSRC} ${CFLAGS} ${STATIC_LIBS}

install:
	${BSD_INSTALL_PROGRAM} ${PROG} ${DESTDIR}${PREFIX}/bin/
	${BSD_INSTALL_MAN} ${PROG}.1 ${DESTDIR}${PREFIX}/share/man/man1
