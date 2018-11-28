$NetBSD: patch-modules_fdlibm_src_math__private.h,v 1.1 2018/05/11 19:18:35 jperkin Exp $

Support SunOS.

--- ../../modules/fdlibm/src/math_private.h.orig	2017-04-11 02:13:20 UTC
+++ ../../modules/fdlibm/src/math_private.h
@@ -38,7 +38,7 @@
  * endianness at run time.
  */
 
-#ifdef WIN32
+#if defined(WIN32) || defined(__sun)
 #define u_int32_t uint32_t
 #define u_int64_t uint64_t
 #endif
