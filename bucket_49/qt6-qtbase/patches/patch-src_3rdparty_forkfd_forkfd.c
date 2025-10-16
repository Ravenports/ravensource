--- src/3rdparty/forkfd/forkfd.c.orig	2025-08-11 04:54:51 UTC
+++ src/3rdparty/forkfd/forkfd.c
@@ -79,9 +79,11 @@
 #endif
 #if (defined(__FreeBSD__) && defined(__FreeBSD_version) && __FreeBSD_version >= 1000032) || \
     (defined(__OpenBSD__) && OpenBSD >= 201505) || \
+    defined(__MidnightBSD__) || \
     (defined(__NetBSD__) && __NetBSD_Version__ >= 600000000)
 #  define HAVE_PIPE2    1
 #endif
+
 #if defined(__FreeBSD__) || defined(__DragonFly__) || defined(__FreeBSD_kernel__) || \
     defined(__OpenBSD__) || defined(__NetBSD__) || defined(__APPLE__)
 #  define HAVE_WAIT4    1
