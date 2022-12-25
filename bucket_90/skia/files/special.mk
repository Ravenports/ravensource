_USES_extract+=	501:make_extdir

.if "${OPSYS}" != "Linux"
_USES_configure+= 452:remove_libdl
.endif

make_extdir:
	${MKDIR} ${WRKSRC}/third_party/externals

remove_libdl:
	@echo "BSD: Remove -ldl linkage"
	${REINPLACE_CMD} -e 's|-ldl||' ${WRKSRC}/public.bzl
	${REINPLACE_CMD} -e 's|"dl"|""|' ${WRKSRC}/BUILD.gn
