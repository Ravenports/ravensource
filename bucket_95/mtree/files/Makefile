PREFIX?=	/usr/local
SRCS=		compare.c create.c excludes.c misc.c mtree.c spec.c \
		verify.c crc.c sha1hl.c
OBJS=		${SRCS:.c=.o}
STATIC_LIBS=	${PREFIX}/libressl/lib/libcrypto.a
CFLAGS=		-I${PREFIX}/libressl/include

.if "${OPSYS}" == "Linux"
STATIC_LIBS+=	${PREFIX}/lib/libbsd.a
CFLAGS+=	-DLIBBSD_OVERLAY -I${PREFIX}/include/bsd -lpthread
.endif

.if "${OPSYS}" == "SunOS"
STATIC_LIBS+=	${PREFIX}/lib/libbsd.a \
		${PREFIX}/lib/libfts.a
CFLAGS+=	-I${PREFIX}/include/bsd
.endif

.SUFFIXES:	.o .c

.c.o:
	${CC} ${_${.IMPSRC:T}_FLAGS} ${CFLAGS} -c ${.IMPSRC}

mtree:	${OBJS}
		${CC} ${CFLAGS} ${.ALLSRC} -o ${.TARGET} ${STATIC_LIBS}
