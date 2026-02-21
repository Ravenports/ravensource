--- src/sys/pekwm_sys.cc.orig	2026-01-03 06:49:57 UTC
+++ src/sys/pekwm_sys.cc
@@ -26,6 +26,10 @@ extern "C" {
 #include <signal.h>
 }
 
+#if !defined(UINT16_MAX)
+#define   UINT16_MAX      0xffff  // hidden on FreeBSD from c++
+#endif
+
 enum PekwmSysAction {
 	PEKWM_SYS_DAY_CHANGED
 };
