--- src/3rdparty/forkfd/forkfd.c.orig	2023-05-12 04:40:15 UTC
+++ src/3rdparty/forkfd/forkfd.c
@@ -74,9 +74,11 @@
 
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
