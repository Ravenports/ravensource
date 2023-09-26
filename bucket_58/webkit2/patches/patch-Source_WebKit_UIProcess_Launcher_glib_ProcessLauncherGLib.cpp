--- Source/WebKit/UIProcess/Launcher/glib/ProcessLauncherGLib.cpp.orig	2023-08-09 08:49:48 UTC
+++ Source/WebKit/UIProcess/Launcher/glib/ProcessLauncherGLib.cpp
@@ -47,9 +47,6 @@
 #include "ProcessProviderLibWPE.h"
 #endif
 
-#if !USE(SYSTEM_MALLOC) && OS(LINUX)
-#include <bmalloc/valgrind.h>
-#endif
 
 namespace WebKit {
 
@@ -91,10 +88,6 @@ static int connectionOptions()
 
 static bool isSandboxEnabled(const ProcessLauncher::LaunchOptions& launchOptions)
 {
-#if !USE(SYSTEM_MALLOC)
-    if (RUNNING_ON_VALGRIND)
-        return false;
-#endif
 
     if (const char* sandboxEnv = g_getenv("WEBKIT_DISABLE_SANDBOX_THIS_IS_DANGEROUS")) {
         if (!strcmp(sandboxEnv, "1"))
