# Emulate USES=waf
MAKE_CMD=	${PYTHON_CMD} ${WRKDIR}/waf-*/waf-light
CONFIGURE_CMD=	${PYTHON_CMD} ${WRKDIR}/waf-*/waf-light configure
MAKEFILE=
MAKE_FLAGS=
MAKE_ARGS+=	--verbose
