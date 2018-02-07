--- src/common/classes/FpeControl.h.orig	2018-02-02 11:00:35 UTC
+++ src/common/classes/FpeControl.h
@@ -223,13 +223,13 @@ inline bool isinf(double x)
 	return (!_finite (x) && !isnan(x));
 }
 #else
-#ifndef isinf
+#if !defined isinf  && !defined __FreeBSD__ && !defined __DragonFly__
 template <typename F>
 inline bool isinf(F x)
 {
 	return !isnan(x) && isnan(x - x);
 }
-#endif // isinf
+#endif // isinf || FreeBSD || DragonFly
 #endif // WIN_NT
 
 namespace Firebird {
