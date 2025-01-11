LIVE555_CFLAGS="\
-I${LOCALBASE}/include/liveMedia\
-I${LOCALBASE}/include/UsageEnvironment\
-I${LOCALBASE}/include/groupsock\
-I${LOCALBASE}/include/BasicUsageEnvironment\
-I${LOCALBASE}/libressl/include"

LIVE555_LIBS="\
-lliveMedia\
-lgroupsock\
-lBasicUsageEnvironment\
-lUsageEnvironment\
-L${LOCALBASE}/libressl/lib -lssl -lcrypto"
