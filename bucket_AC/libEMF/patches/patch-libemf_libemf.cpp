--- libemf/libemf.cpp.orig	2026-05-04 19:14:29 UTC
+++ libemf/libemf.cpp
@@ -20,12 +20,12 @@
  */
 #include <iostream>
 #include <climits>
+#include <functional>
 
 #ifdef __APPLE__
 #include <libkern/OSByteOrder.h>
 #define bswap_32(x) OSSwapInt32(x)
 #else
-#include <byteswap.h>
 #endif
 
 #include "libemf.h"
@@ -79,7 +79,7 @@ namespace EMF {
     if ( not bigEndian() ) {
       return a;
     }
-    return bswap_32(a);
+    return __builtin_bswap32(a);
   }
 
   /*!
