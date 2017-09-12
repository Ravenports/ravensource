.if ${VARIANT:Mpy3*}
setuptools-autolist:
	@(cd ${STAGEDIR}${PREFIX} && \
	${FIND} lib/python* bin share/man share/doc share/examples \
	\( -type f -o -type l \) 2>/dev/null | ${SORT}) \
	>> ${WRKDIR}/.manifest.primary.mktmp
.endif
