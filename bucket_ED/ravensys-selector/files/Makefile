PROG=		selector
SRCS=		selector.c
PREFIX?=	/usr/local
HARDLINKS=	ld

all: ${PROG}

clean:
	rm -f ${OBJS} ${PROG}

${PROG}: ${SRCS}
	${CC} -o ${PROG} ${.ALLSRC} ${CFLAGS}

install:
	cp ${PROG} ${PROG}.unstripped
	strip ${PROG}
.for HL in ${HARDLINKS}
	ln ${PROG} ${DESTDIR}${PREFIX}/libexec/${HL}
.endfor
