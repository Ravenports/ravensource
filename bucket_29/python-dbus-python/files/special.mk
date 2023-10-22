setuptools-autolist:
	# Tailored autolist (avoids catching pc file, supports primary subpackage)
	@(cd ${STAGEDIR}${PREFIX} && \
	${FIND} lib/python* \( -type f -o -type l \) 2>/dev/null | ${SORT}) \
	>> ${WRKDIR}/.manifest.primary.mktmp
