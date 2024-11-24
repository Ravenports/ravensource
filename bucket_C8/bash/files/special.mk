# On linux with glibc, we can't build a fully static bash because
# of absurd restrictions put on static linking with nss, dlopen, etc.
# So we build it dynamic but with libtinfo static.  Leaving glibc-based
# libraries like libc, libm, pthread, etc, is okay.

.if ${OPSYS} == Linux
.  if "${PLIST_SUB:MSTATIC-ON=*}" == "STATIC-ON="
CONFIGURE_ARGS:=	${CONFIGURE_ARGS:N--enable-static-link}

TINFOLIBS=		${LOCALBASE}/lib/libtinfo.a \
			-lpthread

post-configure-opsys:
	${REINPLACE_CMD} -e 's|-ltinfo|${TINFOLIBS}|' ${WRKSRC}/Makefile
.  endif
.endif

# we could have used LDFLAGS_OFF options helper, but it doesn't
# currently exist

.if ${VARIANT} != static
LDFLAGS+=	${VAR1}
.endif
