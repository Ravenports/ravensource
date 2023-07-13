Avoid visibility define that masks usage that is apparently beyond XOPEN or C99.

--- port/cpl_conv.cpp.orig	2023-07-06 11:14:15 UTC
+++ port/cpl_conv.cpp
@@ -48,8 +48,6 @@
 #endif
 #endif
 
-// For atoll (at least for NetBSD)
-#define _ISOC99_SOURCE
 
 #ifdef MSVC_USE_VLD
 #include <vld.h>
