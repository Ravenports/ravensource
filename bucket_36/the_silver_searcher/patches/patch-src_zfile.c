--- src/zfile.c.orig	2018-08-07 06:43:51 UTC
+++ src/zfile.c
@@ -1,4 +1,4 @@
-#ifdef __FreeBSD__
+#if defined __FreeBSD__ || defined __DragonFly__
 #include <sys/endian.h>
 #endif
 #include <sys/types.h>
