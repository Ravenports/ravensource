.if "${VARIANT}" == "standard"
LDFLAGS+=	-lintl
.endif

LDFLAGS+=	-lnsl
