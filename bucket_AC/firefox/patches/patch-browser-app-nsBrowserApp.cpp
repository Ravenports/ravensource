--- browser/app/nsBrowserApp.cpp.orig	2019-02-27 22:18:20 UTC
+++ browser/app/nsBrowserApp.cpp
@@ -275,6 +275,9 @@ int main(int argc, char* argv[], char* e
   }
 #endif
 
+  setenv("MOZ_GMP_PATH", "%%LOCALBASE%%/lib/browser_plugins/symlinks/gecko", 0);
+  setenv("MOZ_PLUGIN_PATH", "%%LOCALBASE%%/lib/browser_plugins/symlinks/gecko", 0);
+
 #ifdef HAS_DLL_BLOCKLIST
   DllBlocklist_Initialize(gBlocklistInitFlags);
 #endif
