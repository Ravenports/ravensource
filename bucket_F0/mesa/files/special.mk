GALLIUM_DRIVERS+=	SWRAST

.if ${OPSYS:MSunOS}
MESON_ARGS+=	-Dshader-cache=false
.endif
