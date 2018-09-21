# MacOS cannot use GNU binutils *at all*.
# Binutils won't build ld, gold, or gas and the utilities
# that do build don't seem to work on Mach-O correctly
# The logic below handles AS and LD configuration

.if "${OPSYS}" == "Darwin"
CONFIGURE_ARGS+=		--with-ld=/usr/bin/ld
CONFIGURE_ARGS+=		--with-as=/usr/bin/as
.else
.  if "${OPSYS}" == "SunOS"
CONFIGURE_ARGS+=		--without-gnu-ld
.  endif
CONFIGURE_ARGS+=		--with-gnu-as
CONFIGURE_ARGS+=		--with-as=${LOCALBASE}/toolchain/bin/as
CONFIGURE_ARGS+=		--with-ld=${LOCALBASE}/toolchain/bin/ld
.endif
