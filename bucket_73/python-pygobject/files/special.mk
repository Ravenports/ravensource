POST_PLIST_TARGET=	autolist

autolist:
	@${ECHO_MSG} "autogenerating manifest ..."
	@(cd ${STAGEDIR}${PREFIX} && ${FIND} lib/py* \
	\( -type f -o -type l \) 2>/dev/null | ${SORT}) \
	>> ${WRKDIR}/.manifest.primary.mktmp
