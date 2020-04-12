--- comm/mail/app/nsMailApp.cpp.orig	2020-04-07 18:05:26 UTC
+++ comm/mail/app/nsMailApp.cpp
@@ -273,6 +273,9 @@ int main(int argc, char* argv[], char* e
   }
 #endif
 
+  setenv("MOZ_GMP_PATH", "%%LOCALBASE%%/lib/browser_plugins/symlinks/gecko", 0);
+  setenv("MOZ_PLUGIN_PATH", "%%LOCALBASE%%/lib/browser_plugins/symlinks/gecko", 0);
+
 #ifdef HAS_DLL_BLOCKLIST
   DllBlocklist_Initialize(gBlocklistInitFlags);
 #endif
