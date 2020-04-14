$NetBSD: patch-ac,v 1.9 2012/07/03 11:31:35 mef Exp $

Add DragonFly

--- qtools/qglobal.h.orig	2020-03-08 15:29:58 UTC
+++ qtools/qglobal.h
@@ -102,7 +102,7 @@
 #define _OS_RELIANTUNIX_
 #elif defined(linux) || defined(__linux) || defined(__linux__) || defined(__GNU__) || defined(__GLIBC__)
 #define _OS_LINUX_
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
 #define _OS_FREEBSD_
 #elif defined(__NetBSD__)
 #define _OS_NETBSD_
