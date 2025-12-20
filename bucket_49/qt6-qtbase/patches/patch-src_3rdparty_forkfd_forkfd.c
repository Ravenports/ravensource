--- src/3rdparty/forkfd/forkfd.c.orig	2025-11-12 10:17:57 UTC
+++ src/3rdparty/forkfd/forkfd.c
@@ -77,8 +77,12 @@
 #  define HAVE_EVENTFD 1
 #  define HAVE_WAITID   1
 #endif
+#if defined(__MidnightBSD__)
+#  define HAVE_WAITID   1
+#endif
 #if (defined(__FreeBSD__) && defined(__FreeBSD_version) && __FreeBSD_version >= 1000032) || \
     (defined(__OpenBSD__) && OpenBSD >= 201505) || \
+    defined(__MidnightBSD__) || \
     (defined(__NetBSD__) && __NetBSD_Version__ >= 600000000)
 #  define HAVE_PIPE2    1
 #endif
