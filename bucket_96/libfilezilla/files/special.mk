# Strip -ldl from all platforms except linux

.if "${OPSYS}" != "Linux"
_USES_configure+= 452:remove_libdl
.endif

remove_libdl:
	@echo "BSD: Remove -ldl linkage"
	${REINPLACE_CMD} -e 's| -ldl||' \
		${WRKSRC}/lib/Makefile.am \
		${WRKSRC}/lib/Makefile.in
