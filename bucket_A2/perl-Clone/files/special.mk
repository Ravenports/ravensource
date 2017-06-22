.if ${OPSYS} == Linux
MAKE_ARGS+=	CCFLAGS="${CFLAGS} -D_GNU_SOURCE"
.endif
