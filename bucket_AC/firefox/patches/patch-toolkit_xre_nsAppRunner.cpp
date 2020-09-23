--- toolkit/xre/nsAppRunner.cpp.orig	2020-09-17 00:32:53 UTC
+++ toolkit/xre/nsAppRunner.cpp
@@ -5156,15 +5156,10 @@ bool BrowserTabsRemoteAutostart() {
     gBrowserTabsRemoteAutostart = true;
   }
 
-  // Uber override pref for emergency blocking
-  if (gBrowserTabsRemoteAutostart) {
-    const char* forceDisable = PR_GetEnv("MOZ_FORCE_DISABLE_E10S");
-    // The environment variable must match the application version to apply.
-    if (forceDisable && gAppData && !strcmp(forceDisable, gAppData->version)) {
+  // Disable MultiProcessing for DragonFly. Slowness and many crashes that require
+  // quite some debugging and investigation.
       gBrowserTabsRemoteAutostart = false;
       status = kE10sForceDisabled;
-    }
-  }
 
   gBrowserTabsRemoteStatus = status;
 
