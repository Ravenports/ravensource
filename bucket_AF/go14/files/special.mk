.if ${ARCH_STANDARD} == "x86_64"
GOARCH=amd64
GOOBJ=6
.elif ${ARCH_STANDARD} == "i386"
GOARCH=i386
GOOBJ=8
.else
GOARCH=unknown
GOOBJ=unknown
.endif

.if ${OPSYS} == "MidnightBSD"
GOSYS=freebsd
.else
GOSYS=${OPSYS:tl}
.endif
