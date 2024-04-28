.if defined(BUILD_WITH_CCACHE)
# disable sccache - it freezes all the time
# MAKE_ENV+=	SCCACHE_DIR=${CCACHE_DIR}/sccache
# MAKE_ENV+=	RUSTC_WRAPPER=${LOCALBASE}/bin/sccache
.endif
