--- vcl/source/app/svapp.cxx.orig	2019-09-18 14:12:06 UTC
+++ vcl/source/app/svapp.cxx
@@ -1163,7 +1163,7 @@ OUString Application::GetHWOSConfInfo()
         aDetails.append( VclResId(SV_APP_DEFAULT) );
     aDetails.append( "; " );
 
-#if (defined LINUX || defined _WIN32 || defined MACOSX)
+#if (defined LINUX || defined _WIN32 || defined MACOSX || defined FREEBSD || defined __DragonFly__)
     aDetails.append( SV_APP_VCLBACKEND );
     aDetails.append( GetToolkitName() );
     aDetails.append( "; " );
