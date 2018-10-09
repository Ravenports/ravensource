all: libdl.a

.if ${OPSYS} == Linux || ${OPSYS} == SunOS || ${OPSYS} == Darwin
TSORT=		tsort 2>/dev/null
.else
TSORT=		tsort -q
.endif

install:
	${BSD_INSTALL_DATA} libdl.a ${DESTDIR}${PREFIX}/lib

libdl.a: dl_stub.o
	ar cq ${.TARGET} `lorder ${.ALLSRC} | ${TSORT}`
	ranlib ${.TARGET}

dl_stub.c:
	@echo "/*" > ${.TARGET}
	@echo " * BSD provides the dynamic loader facilities (dlopen/dlfcn/...) in" >> ${.TARGET}
	@echo " * libc itself. However, a number of applications expect these routines to" >> ${.TARGET}
	@echo " * be provided by libdl. We provide a stub libdl with no subroutines to satisfy" >> ${.TARGET}
	@echo " * these applications." >> ${.TARGET}
	@echo " */" >> ${.TARGET}

dl_stub.o: dl_stub.c
	${CC} -c ${.ALLSRC} -fPIC -o ${.TARGET}

clean:
	rm -f libdl.a dl_stub.c dl_stub.o
