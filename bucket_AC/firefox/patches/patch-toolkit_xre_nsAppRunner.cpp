--- toolkit/xre/nsAppRunner.cpp.orig	2020-04-03 19:35:39 UTC
+++ toolkit/xre/nsAppRunner.cpp
@@ -4991,7 +4991,13 @@ bool BrowserTabsRemoteAutostart() {
   }
 
   // Uber override pref for emergency blocking
+#ifdef __DragonFly__
+  // Disable MultiProcessing for DragonFly. Slowness and many crashes that require
+  // quite some debugging and investigation.
+  {
+#else
   if (gBrowserTabsRemoteAutostart && EnvHasValue("MOZ_FORCE_DISABLE_E10S")) {
+#endif
     gBrowserTabsRemoteAutostart = false;
     status = kE10sForceDisabled;
   }
