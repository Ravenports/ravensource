--- compat/compat.h.orig	2021-01-26 02:41:10 UTC
+++ compat/compat.h
@@ -1,7 +1,7 @@
 #include <sys/types.h>
 #include <stdarg.h>
 
-#if !defined(__NetBSD__)
+#if !defined(__NetBSD__) && !defined(__DragonFly__) && !defined(__FreeBSD__)
 void closefrom(int lowfd);
 #endif
 
