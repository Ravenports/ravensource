--- src/sys/pekwm_sys.cc.orig	2025-11-29 07:14:04 UTC
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
