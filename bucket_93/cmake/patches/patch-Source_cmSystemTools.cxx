--- Source/cmSystemTools.cxx.orig	2020-07-15 11:19:20 UTC
+++ Source/cmSystemTools.cxx
@@ -5,7 +5,7 @@
 // POSIX APIs are needed
 #  define _POSIX_C_SOURCE 200809L
 #endif
-#if defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__NetBSD__)
+#if defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
 // For isascii
 #  define _XOPEN_SOURCE 700
 #endif
