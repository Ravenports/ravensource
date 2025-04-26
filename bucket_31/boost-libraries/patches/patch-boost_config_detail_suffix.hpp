$NetBSD: patch-boost_config_detail_suffix.hpp,v 1.1 2017/08/24 19:31:32 adam Exp $

--- boost/config/detail/suffix.hpp.orig	2025-04-03 11:37:23 UTC
+++ boost/config/detail/suffix.hpp
@@ -264,7 +264,7 @@
 //
 #if (defined(__MT__) || defined(_MT) || defined(_REENTRANT) \
     || defined(_PTHREADS) || defined(__APPLE__) || defined(__DragonFly__)) \
-    && !defined(BOOST_HAS_THREADS)
+    || defined(__NetBSD__) && !defined(BOOST_HAS_THREADS)
 #  define BOOST_HAS_THREADS
 #endif
 
