$NetBSD: patch-boost_math_special__functions_log1p.hpp,v 1.1 2017/05/29 14:39:29 ryoon Exp $

--- boost/math/special_functions/log1p.hpp.orig	2025-04-03 11:37:27 UTC
+++ boost/math/special_functions/log1p.hpp
@@ -328,7 +328,7 @@ BOOST_MATH_GPU_ENABLED inline typename t
 #  undef log1p
 #endif
 
-#if defined(BOOST_HAS_LOG1P) && !(defined(__osf__) && defined(__DECCXX_VER))
+#if defined(BOOST_HAS_LOG1P) && !(defined(__osf__) && defined(__DECCXX_VER)) && !defined(__NetBSD__)
 #  ifdef BOOST_MATH_USE_C99
 template <class Policy>
 BOOST_MATH_GPU_ENABLED inline float log1p(float x, const Policy& pol)
