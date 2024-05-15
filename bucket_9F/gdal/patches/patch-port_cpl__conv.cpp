Avoid visibility define that masks usage that is apparently beyond XOPEN or C99.

--- port/cpl_conv.cpp.orig	2024-05-07 12:53:29 UTC
+++ port/cpl_conv.cpp
@@ -48,11 +48,6 @@
 #endif
 #endif
 
-// For atoll (at least for NetBSD)
-#ifndef _ISOC99_SOURCE
-#define _ISOC99_SOURCE
-#endif
-
 #ifdef MSVC_USE_VLD
 #include <vld.h>
 #endif
