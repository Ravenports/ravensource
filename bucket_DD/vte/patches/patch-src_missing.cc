--- src/missing.cc.orig	2025-04-13 07:54:57 UTC
+++ src/missing.cc
@@ -125,7 +125,7 @@ getrlimit_NOFILE_max(void)
 
 #endif /* HAVE_SYS_RESOURCE_H */
 
-#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__APPLE__)
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__APPLE__) || defined(__DragonFly__)
         /* Use sysconf() function provided by the system if it is known to be
          * async-signal safe.
          */
