--- vcl/unx/generic/app/geninst.cxx.orig	2022-11-16 17:29:15 UTC
+++ vcl/unx/generic/app/geninst.cxx
@@ -22,7 +22,7 @@
 #if defined(LINUX)
 #  include <stdio.h>
 #endif
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__)
 #  include <sys/utsname.h>
 #endif
 
@@ -72,7 +72,7 @@ OUString SalGenericInstance::getOSVersio
         }
         fclose( pVersion );
     }
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__)
     struct utsname stName;
     if ( uname( &stName ) != 0 )
         return aKernelVer;
