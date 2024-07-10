--- utils/pxattr.cpp.orig	2024-05-23 07:18:55 UTC
+++ utils/pxattr.cpp
@@ -42,7 +42,7 @@
 
 // Not exactly true for win32, but makes my life easier by avoiding ifdefs in recoll (the calls just
 // fail, which is expected)
-#if defined(__DragonFly__) || defined(__OpenBSD__) || defined(_WIN32)
+#if defined(__DragonFly__) || defined(__OpenBSD__) || defined(_WIN32) || defined(__NetBSD__)
 #define HAS_NO_XATTR
 #endif
 
