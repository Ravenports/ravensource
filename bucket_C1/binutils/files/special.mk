# Consider making gold the default linker on DF and Linux

.if "${OPSYS}" == "DragonFly"
BUILD_GOLD=		yes
GOLD_CONFIG=		--enable-gold
.elif "${OPSYS}" == "FreeBSD"
.  if "${STANDARD_ARCH}" == "x86_64" || "${STANDARD_ARCH}" == "aarch64"
BUILD_GOLD=		yes
GOLD_CONFIG=		--enable-gold=default
.  endif
.elif "${OPSYS}" == "Linux"
.  if "${STANDARD_ARCH}" == "x86_64" || "${STANDARD_ARCH}" == "aarch64"
BUILD_GOLD=		yes
GOLD_CONFIG=		--enable-gold
.  endif
.elif "${OPSYS}" == "SunOS"
BUILD_GOLD=		yes
GOLD_CONFIG=		--enable-gold
.endif


.if defined(BUILD_GOLD)
CONFIGURE_ARGS+=	${GOLD_CONFIG}
CONFIGURE_ARGS+=	--enable-plugins
PLIST_SUB+=		GOLD=""
PLIST_SUB+=		PLUGINAPI=""
.else
CONFIGURE_ARGS+=	--disable-gold
CONFIGURE_ARGS+=	--disable-plugins
PLIST_SUB+=		GOLD="@comment "
.  if "${OPSYS}" == "Darwin"
PLIST_SUB+=		PLUGINAPI=""
.  else
PLIST_SUB+=		PLUGINAPI="@comment "
.  endif
.endif

.if "${OPSYS}" == "Darwin"
PLIST_SUB+=		LINKER="@comment "
PLIST_SUB+=		ASSEMBLER="@comment "
PLIST_SUB+=		GPROF="@comment "
.else
PLIST_SUB+=		LINKER=""
PLIST_SUB+=		ASSEMBLER=""
PLIST_SUB+=		GPROF=""
.endif
