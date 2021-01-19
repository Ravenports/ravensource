--- vcl/source/app/svapp.cxx.orig	2021-01-14 20:00:32 UTC
+++ vcl/source/app/svapp.cxx
@@ -1178,7 +1178,7 @@ OUString Application::GetHWOSConfInfo(co
 #endif
             appendDetails(u"", Localize(SV_APP_DEFAULT, bLocalize));
 
-#if (defined LINUX || defined _WIN32 || defined MACOSX || defined __FreeBSD__)
+#if (defined LINUX || defined _WIN32 || defined MACOSX || defined __DragonFly__ || defined __FreeBSD__)
         appendDetails(u"; ", SV_APP_VCLBACKEND + GetToolkitName());
 #endif
     }
