--- Source/cmSystemTools.cxx.orig	2021-04-08 12:00:50 UTC
+++ Source/cmSystemTools.cxx
@@ -7,6 +7,7 @@
 #  define _POSIX_C_SOURCE 200809L
 #endif
 #if defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__NetBSD__) ||    \
+  defined(__DragonFly__) || \
   defined(__QNX__)
 // For isascii
 // NOLINTNEXTLINE(bugprone-reserved-identifier)
