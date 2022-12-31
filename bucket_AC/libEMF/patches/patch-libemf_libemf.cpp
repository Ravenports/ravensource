--- libemf/libemf.cpp.orig	2020-06-07 13:10:20 UTC
+++ libemf/libemf.cpp
@@ -72,8 +72,7 @@ namespace EMF {
     if ( not bigEndian() ) {
       return a;
     }
-#include <byteswap.h>
-    return bswap_32(a);
+    return __builtin_bswap32(a);
   }
 
   /*!
