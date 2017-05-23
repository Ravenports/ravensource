PROG=		rpcgen
SRCS=		rpc_main.c rpc_clntout.c rpc_cout.c rpc_hout.c rpc_parse.c \
		rpc_sample.c rpc_scan.c rpc_svcout.c rpc_tblout.c rpc_util.c
OBJS=		${SRCS:.c=.o}
PREFIX?=	/usr/local

.if ${OPSYS} == Linux
LIBS+=		${PREFIX}/lib/libbsd.a
.endif

all: ${PROG}

clean:
	rm -f ${OBJS} ${PROG}

${PROG}: ${SRCS}
	${CC} -o ${PROG} ${.ALLSRC} ${CFLAGS} ${LIBS}

install:
	${BSD_INSTALL_PROGRAM} ${PROG} ${DESTDIR}${PREFIX}/bin/
	${BSD_INSTALL_MAN} ${PROG}.1 ${DESTDIR}${PREFIX}/share/man/man1
