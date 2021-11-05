Avoid visibility define that masks usage that is apparently beyond XOPEN or C99.

--- port/cpl_conv.cpp.orig	2021-10-25 11:42:52 UTC
+++ port/cpl_conv.cpp
@@ -37,15 +37,7 @@
 #endif
 #define _XOPEN_SOURCE 600
 #endif
-#else
-#ifdef _XOPEN_SOURCE
-#undef _XOPEN_SOURCE
 #endif
-#define _XOPEN_SOURCE 700
-#endif
-
-// For atoll (at least for NetBSD)
-#define _ISOC99_SOURCE
 
 #ifdef MSVC_USE_VLD
 #include <vld.h>
