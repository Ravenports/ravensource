$NetBSD: patch-boost_math_special__functions_log1p.hpp,v 1.1 2017/05/29 14:39:29 ryoon Exp $

--- boost/math/special_functions/log1p.hpp.orig	2023-08-08 21:02:53 UTC
+++ boost/math/special_functions/log1p.hpp
@@ -325,7 +325,7 @@ inline typename tools::promote_args<T>::
 #  undef log1p
 #endif
 
-#if defined(BOOST_HAS_LOG1P) && !(defined(__osf__) && defined(__DECCXX_VER))
+#if defined(BOOST_HAS_LOG1P) && !(defined(__osf__) && defined(__DECCXX_VER)) && !defined(__NetBSD__)
 #  ifdef BOOST_MATH_USE_C99
 template <class Policy>
 inline float log1p(float x, const Policy& pol)
