--- vcl/source/app/svapp.cxx.orig	2021-12-21 19:06:48 UTC
+++ vcl/source/app/svapp.cxx
@@ -1198,7 +1198,7 @@ OUString Application::GetHWOSConfInfo(co
 #endif
             appendDetails(u"", Localize(SV_APP_DEFAULT, bLocalize));
 
-#if (defined LINUX || defined _WIN32 || defined MACOSX || defined __FreeBSD__)
+#if (defined LINUX || defined _WIN32 || defined MACOSX || defined __DragonFly__ || defined __FreeBSD__)
         appendDetails(u"; ", SV_APP_VCLBACKEND + GetToolkitName());
 #endif
     }
