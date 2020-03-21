--- browser/app/nsBrowserApp.cpp.orig	2020-03-09 13:09:13 UTC
+++ browser/app/nsBrowserApp.cpp
@@ -313,6 +313,9 @@ int main(int argc, char* argv[], char* e
   }
 #endif
 
+  setenv("MOZ_GMP_PATH", "/raven/lib/browser_plugins/symlinks/gecko", 0);
+  setenv("MOZ_PLUGIN_PATH", "/raven/lib/browser_plugins/symlinks/gecko", 0);
+
 #ifdef HAS_DLL_BLOCKLIST
   DllBlocklist_Initialize(gBlocklistInitFlags);
 #endif
