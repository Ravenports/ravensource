--- src/config.h.orig	2018-11-07 12:23:06 UTC
+++ src/config.h
@@ -62,7 +62,7 @@
 #endif
 
 /* Test for backtrace() */
-#if defined(__APPLE__) || (defined(__linux__) && defined(__GLIBC__))
+#if defined(__APPLE__) || (defined(__linux__) && defined(__GLIBC__)) || defined(__FreeBSD__)
 #define HAVE_BACKTRACE 1
 #endif
 
