.if defined(BUILD_GOLD)
CONFIGURE_ARGS+=	${GOLD_CONFIG}
CONFIGURE_ARGS+=	--enable-plugins
PLIST_SUB+=		GOLD=""
.else
CONFIGURE_ARGS+=	--disable-gold
CONFIGURE_ARGS+=	--disable-plugins
PLIST_SUB+=		GOLD="@comment "
.endif
