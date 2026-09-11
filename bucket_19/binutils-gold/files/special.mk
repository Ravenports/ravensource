.if defined(BUILD_GOLD)
CONFIGURE_ARGS+=	${GOLD_CONFIG}
PLIST_SUB+=		GOLD=""
.else
CONFIGURE_ARGS+=	--disable-gold
PLIST_SUB+=		GOLD="@comment "
.endif

# for non-GNU linkers, ensure DT_RPATH set instead of DT_RUNPATH
# See rtld man page, we need to be invulnerable to LD_LIBRARY_PATH
.if ${OPSYS} != SunOS
LDFLAGS+= -Wl,--disable-new-dtags
.endif
