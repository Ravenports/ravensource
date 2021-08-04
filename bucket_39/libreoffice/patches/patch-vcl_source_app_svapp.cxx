--- vcl/source/app/svapp.cxx.orig	2021-07-28 20:03:57 UTC
+++ vcl/source/app/svapp.cxx
@@ -1195,7 +1195,7 @@ OUString Application::GetHWOSConfInfo(co
 #endif
             appendDetails(u"", Localize(SV_APP_DEFAULT, bLocalize));
 
-#if (defined LINUX || defined _WIN32 || defined MACOSX || defined __FreeBSD__)
+#if (defined LINUX || defined _WIN32 || defined MACOSX || defined __DragonFly__ || defined __FreeBSD__)
         appendDetails(u"; ", SV_APP_VCLBACKEND + GetToolkitName());
 #endif
     }
