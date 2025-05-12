Avoid visibility define that masks usage that is apparently beyond XOPEN or C99.

--- port/cpl_conv.cpp.orig	2025-05-06 16:38:15 UTC
+++ port/cpl_conv.cpp
@@ -32,11 +32,6 @@
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
