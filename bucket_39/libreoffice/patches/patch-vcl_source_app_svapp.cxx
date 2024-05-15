--- vcl/source/app/svapp.cxx.orig	2024-04-29 18:46:10 UTC
+++ vcl/source/app/svapp.cxx
@@ -1229,7 +1229,7 @@ OUString Application::GetHWOSConfInfo(co
 #endif
             appendDetails(u"", Localize(SV_APP_DEFAULT, bLocalize));
 
-#if (defined LINUX || defined _WIN32 || defined MACOSX || defined __FreeBSD__ || defined EMSCRIPTEN)
+#if (defined LINUX || defined _WIN32 || defined MACOSX || defined __DragonFly__ || defined __FreeBSD__ || defined EMSCRIPTEN)
         appendDetails(u"; ", SV_APP_VCLBACKEND + GetToolkitName());
 #endif
     }
