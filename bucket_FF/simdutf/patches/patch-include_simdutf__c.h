Modern c++ compilers have char16_t as a reserved keyword.
Since NetBSD doesn't have /usr/include/uchar, it runs this deleted macro and
breaks with invalid conversion errors.

--- include/simdutf_c.h.orig	2026-01-13 08:03:21 UTC
+++ include/simdutf_c.h
@@ -12,18 +12,6 @@
 #include <stdbool.h>
 #include <stdint.h>
 
-#ifdef __has_include
-  #if __has_include(<uchar.h>)
-    #include <uchar.h>
-  #else // __has_include(<uchar.h>)
-    #define char16_t uint16_t
-    #define char32_t uint32_t
-  #endif // __has_include(<uchar.h>)
-#else    // __has_include(<uchar.h>)
-  #define char16_t uint16_t
-  #define char32_t uint32_t
-#endif // __has_include
-
 #ifdef __cplusplus
 extern "C" {
 #endif
