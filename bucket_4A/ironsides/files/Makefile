all: build

build:
	gnatmake -p -P ironsides

install:
	mkdir -p ${DESTDIR}${PREFIX}/share/ironsides
	${BSD_INSTALL_PROGRAM} final/spark_dns_main \
		${DESTDIR}${PREFIX}/sbin/ironsides
	${BSD_INSTALL_DATA} dfcs.usafa.edu.zonefile \
		${DESTDIR}${PREFIX}/share/ironsides/
	${BSD_INSTALL_MAN} ironsides.1 ${DESTDIR}${MANPREFIX}/man/man1/
