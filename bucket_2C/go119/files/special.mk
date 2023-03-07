.if ${ARCH_STANDARD} == "x86_64"
GOARCH=amd64
.elif ${ARCH_STANDARD} == "i386"
GOARCH=i386
.else
GOARCH=unknown
.endif
