.if ${OPSYS} != Linux
pre-configure:
	# remove -ldl from pc file
	sed -i.bak -e 's/ -ldl//' ${WRKSRC}/etc/luajit.pc
.endif
