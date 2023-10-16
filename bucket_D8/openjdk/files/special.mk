.if defined(BUILD_WITH_CCACHE)
CONFIGURE_ARGS+=	--enable-ccache
.else
CONFIGURE_ARGS+=	--disable-ccache
.endif
