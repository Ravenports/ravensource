all: generic

autoselect.c: autoselect.c.in
	sed -e "s|%%SSL_VARIANT%%|${SSL_VARIANT}|" \
	    -e "s|%%PREFIX%%|${PREFIX}|g" ${.ALLSRC} > ${.TARGET}

generic: autoselect.c
	${CC} ${CFLAGS} ${LDFLAGS} -o ${.TARGET} ${.ALLSRC}

install:
.for prog in openssl c_rehash nc ocspcheck
	${BSD_INSTALL_PROGRAM} generic ${DESTDIR}${PREFIX}/bin/${prog}
.endfor
