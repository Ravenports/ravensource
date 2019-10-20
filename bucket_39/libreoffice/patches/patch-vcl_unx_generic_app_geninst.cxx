--- vcl/unx/generic/app/geninst.cxx.orig	2019-09-18 14:12:06 UTC
+++ vcl/unx/generic/app/geninst.cxx
@@ -22,6 +22,9 @@
 #include <cassert>
 #include <string.h>
 #include <stdlib.h>
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+#include <sys/utsname.h>
+#endif
 
 #if defined(LINUX)
 #  include <stdio.h>
@@ -54,10 +57,10 @@ SalGenericInstance::~SalGenericInstance(
 
 OUString SalGenericInstance::getOSVersion()
 {
+#if defined(LINUX)
     OUString aKernelVer = "unknown";
 
 // not so generic, but at least shared between all unix backend
-#if defined(LINUX)
     FILE* pVersion = fopen( "/proc/version", "r" );
     if ( pVersion )
     {
@@ -76,8 +79,28 @@ OUString SalGenericInstance::getOSVersio
         }
         fclose( pVersion );
     }
-#endif
     return aKernelVer;
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
+    struct utsname stName;
+
+    if ( uname( &stName ) != 0 )
+       return "unknown";
+
+    sal_Int32 nDots = 0;
+    sal_Int32 nIndex = 0;
+    OUString aVers = OUString::createFromAscii( stName.release );
+    while ( nIndex++ < aVers.getLength() )
+    {
+        const char c = stName.release[ nIndex ];
+        if ( c == ' ' || c == '-' || ( c == '.' && nDots++ > 0 ) )
+            break;
+    }
+    return OUString::createFromAscii( stName.sysname ) + " " +
+        aVers.copy( 0, nIndex );
+#else
+    OUString aKernelVer = "unknown";
+    return aKernelVer;
+#endif
 }
 
 /* vim:set shiftwidth=4 softtabstop=4 expandtab: */
