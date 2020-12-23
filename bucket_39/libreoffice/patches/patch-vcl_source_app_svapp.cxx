--- vcl/source/app/svapp.cxx.orig	2020-08-12 13:23:59 UTC
+++ vcl/source/app/svapp.cxx
@@ -1191,7 +1191,7 @@ OUString Application::GetHWOSConfInfo(co
 #endif
             appendDetails("", Localize(SV_APP_DEFAULT, bLocalize));
 
-#if (defined LINUX || defined _WIN32 || defined MACOSX)
+#if (defined LINUX || defined _WIN32 || defined MACOSX || defined FREEBSD || defined __DragonFly__)
         appendDetails("; ", SV_APP_VCLBACKEND + GetToolkitName());
 #endif
     }
