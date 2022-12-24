# Strip -ldl from all platforms except linux

.if "${OPSYS}" != "Linux"
_USES_configure+= 452:remove_libdl
.endif

remove_libdl:
	@echo "BSD: Remove -ldl and -lrt linkage"
	${REINPLACE_CMD} -e '/ -lrt/d; s| -ldl||' \
		${WRKSRC}/samples/source/Makefile.in \
		${WRKSRC}/exempi/Makefile.in	
