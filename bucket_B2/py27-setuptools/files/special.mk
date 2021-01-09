PYDISTUTILS_SETUP= ${LOCALBASE}/bin/python2.7 -c "import sys; \
import setuptools; \
__file__='setup.py'; \
sys.argv[0]='setup.py'; \
exec(compile(open(__file__, 'rb').read().replace(b'\\r\\n', b'\\n'), __file__, 'exec'))"

POST_PLIST_TARGET=	setuptools-autolist

setuptools-autolist:
	@(cd ${STAGEDIR}${PREFIX} && ${FIND} lib \
	\( -type f -o -type l \) 2>/dev/null | ${SORT}) \
	>> ${WRKDIR}/.manifest.single.mktmp
