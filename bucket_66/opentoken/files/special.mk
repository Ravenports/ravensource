OTLIBVER=	5.0.0

.if "${OPSYS}" == "Darwin"
FINALLIB=	libopentoken.${OTLIBVER}.dylib
.else
FINALLIB=	libopentoken.so.${OTLIBVER}
.endif