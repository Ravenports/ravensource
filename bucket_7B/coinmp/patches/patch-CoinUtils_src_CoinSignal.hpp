--- CoinUtils/src/CoinSignal.hpp.orig	2015-03-13 20:16:34 UTC
+++ CoinUtils/src/CoinSignal.hpp
@@ -43,8 +43,15 @@
 
 //-----------------------------------------------------------------------------
 
+#if defined(__DragonFly__) && defined(__GNUC__)
+   typedef typeof(SIG_DFL) CoinSighandler_t;
+#  define CoinSighandler_t_defined
+#endif
+
+//-----------------------------------------------------------------------------
+
 #if defined(__FreeBSD__) && defined(__GNUC__)
-   typedef __decltype(SIG_DFL) CoinSighandler_t;
+   typedef typeof(SIG_DFL) CoinSighandler_t;
 #  define CoinSighandler_t_defined
 #endif
 
