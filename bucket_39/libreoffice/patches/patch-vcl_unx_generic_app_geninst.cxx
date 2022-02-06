--- vcl/unx/generic/app/geninst.cxx.orig	2022-01-26 14:35:29 UTC
+++ vcl/unx/generic/app/geninst.cxx
@@ -22,7 +22,7 @@
 #if defined(LINUX)
 #  include <stdio.h>
 #endif
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__)
 #  include <sys/utsname.h>
 #endif
 
@@ -73,7 +73,7 @@ OUString SalGenericInstance::getOSVersio
         fclose( pVersion );
     }
     return aKernelVer;
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__)
     struct utsname stName;
     if ( uname( &stName ) != 0 )
         return aKernelVer;
