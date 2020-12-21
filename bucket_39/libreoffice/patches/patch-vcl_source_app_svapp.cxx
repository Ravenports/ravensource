--- vcl/source/app/svapp.cxx.orig	2020-12-09 18:56:14 UTC
+++ vcl/source/app/svapp.cxx
@@ -1186,7 +1186,7 @@ OUString Application::GetHWOSConfInfo(co
 #endif
             appendDetails("", Localize(SV_APP_DEFAULT, bLocalize));
 
-#if (defined LINUX || defined _WIN32 || defined MACOSX)
+#if (defined LINUX || defined _WIN32 || defined MACOSX || defined FREEBSD || defined __DragonFly__)
         appendDetails("; ", SV_APP_VCLBACKEND + GetToolkitName());
 #endif
     }
