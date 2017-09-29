# Emulate USES=waf
MAKE_CMD=	${LOCALBASE}/bin/python2.7 ./waf
CONFIGURE_CMD=	${LOCALBASE}/bin/python2.7 ./waf configure
MAKEFILE=
MAKE_FLAGS=
MAKE_ARGS+=	--verbose
