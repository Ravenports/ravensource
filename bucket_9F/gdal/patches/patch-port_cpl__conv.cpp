Avoid visibility define that masks usage that is apparently beyond XOPEN or C99.

--- port/cpl_conv.cpp.orig	2024-01-04 18:08:59 UTC
+++ port/cpl_conv.cpp
@@ -48,8 +48,6 @@
 #endif
 #endif
 
-// For atoll (at least for NetBSD)
-#define _ISOC99_SOURCE
 
 #ifdef MSVC_USE_VLD
 #include <vld.h>
