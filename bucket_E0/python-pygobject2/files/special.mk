POST_PLIST_TARGET=	autolist

autolist:
	@${ECHO_MSG} "autogenerating manifest ..."
	@(cd ${STAGEDIR}${PREFIX} && ${FIND} bin share/py* include/py* lib \
	\( -type f -o -type l \) 2>/dev/null | ${SORT}) \
	>> ${WRKDIR}/.manifest.single.mktmp
