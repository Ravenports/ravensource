--- src/base/endianfns.h.orig	2025-01-01 14:40:35 UTC
+++ src/base/endianfns.h
@@ -63,7 +63,11 @@
 
 #else
 /* for Linux and others use definitions from endian.h */
+# if defined(__FreeBSD__) || defined(__NetBSD__)
+#  include <sys/endian.h>
+# else
 #  include <endian.h>
+# endif
 
 #  define GWEN_ENDIAN_LE16TOH(x) le16toh(x)
 #  define GWEN_ENDIAN_HTOLE16(x) htole16(x)
