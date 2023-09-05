.if defined(BUILD_WITH_CCACHE)
# QMAKE_ARGS+=	--with-ccache=${LOCALBASE}/bin/sccache
MAKE_ENV+=	SCCACHE_DIR=${CCACHE_DIR}/sccache
MAKE_ENV+=	RUSTC_WRAPPER=${LOCALBASE}/bin/sccache
.endif
