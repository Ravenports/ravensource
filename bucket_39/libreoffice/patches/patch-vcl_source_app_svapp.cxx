--- vcl/source/app/svapp.cxx.orig	2023-08-23 11:52:34 UTC
+++ vcl/source/app/svapp.cxx
@@ -1208,7 +1208,7 @@ OUString Application::GetHWOSConfInfo(co
 #endif
             appendDetails(u"", Localize(SV_APP_DEFAULT, bLocalize));
 
-#if (defined LINUX || defined _WIN32 || defined MACOSX || defined __FreeBSD__ || defined EMSCRIPTEN)
+#if (defined LINUX || defined _WIN32 || defined MACOSX || defined __DragonFly__ || defined __FreeBSD__ || defined EMSCRIPTEN)
         appendDetails(u"; ", SV_APP_VCLBACKEND + GetToolkitName());
 #endif
     }
