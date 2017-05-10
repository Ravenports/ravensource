POST_PLIST_TARGET=	ravenports-autolist

ravenports-autolist:
	@(cd ${STAGEDIR}${PREFIX} && ${FIND} share \
	\( -type f -o -type l \) 2>/dev/null | ${SORT}) \
	>> ${WRKDIR}/.manifest.single.mktmp
