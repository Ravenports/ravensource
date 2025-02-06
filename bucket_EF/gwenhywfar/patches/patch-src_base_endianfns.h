--- src/base/endianfns.h.orig	2017-08-07 19:02:11 UTC
+++ src/base/endianfns.h
@@ -40,7 +40,11 @@
 #  define GWEN_ENDIAN_HTOLE64(x) (x)
 #else
 /* for Linux and others use definitions from endian.h */
+# if defined(__FreeBSD__)
+#  include <sys/endian.h>
+# else
 #  include <endian.h>
+# endif
 
 #  define GWEN_ENDIAN_LE16TOH(x) le16toh(x)
 #  define GWEN_ENDIAN_HTOLE16(x) htole16(x)
