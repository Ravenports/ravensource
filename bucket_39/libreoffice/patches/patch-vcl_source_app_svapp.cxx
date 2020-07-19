--- vcl/source/app/svapp.cxx.orig	2020-07-15 18:21:20 UTC
+++ vcl/source/app/svapp.cxx
@@ -1183,7 +1183,7 @@ OUString Application::GetHWOSConfInfo(co
 #endif
             appendDetails("", VclResId(SV_APP_DEFAULT));
 
-#if (defined LINUX || defined _WIN32 || defined MACOSX)
+#if (defined LINUX || defined _WIN32 || defined MACOSX || defined FREEBSD || defined __DragonFly__)
         appendDetails("; ", SV_APP_VCLBACKEND + GetToolkitName());
 #endif
     }
