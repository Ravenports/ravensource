--- lib/freebl/verified/kremlib.h.orig	2019-01-25 23:52:51 UTC
+++ lib/freebl/verified/kremlib.h
@@ -184,7 +184,10 @@ typedef const char *Prims_string;
 /* ... for Linux */
 #if defined(__linux__) || defined(__CYGWIN__)
 #include <endian.h>
-
+/* ... for BSDs */
+#elif defined(__DragonFly__) || defined(__FreeBSD__) \
+   || defined(__NetBSD__) || defined(__OpenBSD__)
+#include <sys/endian.h>
 /* ... for OSX */
 #elif defined(__APPLE__)
 #include <libkern/OSByteOrder.h>
