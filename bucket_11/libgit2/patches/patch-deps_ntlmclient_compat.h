--- deps/ntlmclient/compat.h.orig	2020-06-04 08:46:58 UTC
+++ deps/ntlmclient/compat.h
@@ -29,7 +29,7 @@
 /* See man page htobe64(3) */
 # include <endian.h>
 # define htonll htobe64
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
 /* See man page bwaps64(9) */
 # include <sys/endian.h>
 # define htonll htobe64
