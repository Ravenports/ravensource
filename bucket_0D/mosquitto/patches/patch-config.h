--- config.h.orig	2023-09-18 21:29:34 UTC
+++ config.h
@@ -6,10 +6,14 @@
 
 #ifdef __APPLE__
 #  define __DARWIN_C_SOURCE
-#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__SYMBIAN32__)
+#elif defined(__FreeBSD__) || defined(__SYMBIAN32__) || defined(__DragonFly__)
 #  define _XOPEN_SOURCE 700
 #  define __BSD_VISIBLE 1
 #  define HAVE_NETINET_IN_H
+#elif defined(__NetBSD__)
+#  define _XOPEN_SOURCE 700
+#  define _NETBSD_SOURCE 1
+#  define HAVE_NETINET_IN_H
 #elif defined(__QNX__)
 #  define _XOPEN_SOURCE 600
 #  define __BSD_VISIBLE 1
