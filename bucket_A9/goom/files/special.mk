_USES_configure+=	427:midgoom

midgoom:
	@${ECHO_MSG} "===>  Second configure script fix for MidnightBSD"
	${SED} -i.mbsd2 \
		-e 's#freebsd\*)#freebsd* | dragonfly* | midnight*)#' \
		${WRKSRC}/configure
