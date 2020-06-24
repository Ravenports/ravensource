--- compat/compat.h.orig	2020-06-21 14:08:22 UTC
+++ compat/compat.h
@@ -1,7 +1,7 @@
 #include <sys/types.h>
 #include <stdarg.h>
 
-#if !defined(__NetBSD__)
+#if !defined(__NetBSD__) && !defined(__DragonFly__) && !defined(__FreeBSD__)
 void closefrom(int lowfd);
 #endif
 
