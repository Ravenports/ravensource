setuptools-autolist:
	@echo "[Packing build python modules]"
	@(cd ${STAGEDIR}${PREFIX} && \
		${FIND} lib/pyth* \( -type f -o -type l \) 2>/dev/null | ${SORT}) \
		>> ${WRKDIR}/.manifest.modules.mktmp
