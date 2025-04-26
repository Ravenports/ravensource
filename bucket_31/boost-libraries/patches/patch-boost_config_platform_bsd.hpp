$NetBSD: patch-boost_config_platform_bsd.hpp,v 1.2 2021/09/29 16:11:04 adam Exp $

--- boost/config/platform/bsd.hpp.orig	2025-04-03 11:37:23 UTC
+++ boost/config/platform/bsd.hpp
@@ -38,7 +38,7 @@
 // and not in <unistd.h>
 //
 #if (defined(__FreeBSD__) && (__FreeBSD__ <= 3))\
-   || defined(__OpenBSD__) || defined(__DragonFly__) 
+   || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__NetBSD__)
 #  define BOOST_HAS_PTHREADS
 #endif
 
@@ -64,7 +64,7 @@
 //
 // The BSD <ctype.h> has macros only, no functions:
 //
-#if !defined(__OpenBSD__) || defined(__DragonFly__)
+#if defined(__FreeBSD__) || defined(__DragonFly__)
 #  define BOOST_NO_CTYPE_FUNCTIONS
 #endif
 
