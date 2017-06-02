POST_PLIST_TARGET=	my-autolist

my-autolist:
	(cd ${STAGEDIR}${PREFIX} && ${FIND} lib/py* \
	\( -type f -o -type l \) 2>/dev/null | ${SORT}) \
	>> ${WRKDIR}/.manifest.single.mktmp
