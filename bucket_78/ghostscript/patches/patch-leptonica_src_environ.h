--- leptonica/src/environ.h.orig	2023-03-27 06:53:17 UTC
+++ leptonica/src/environ.h
@@ -172,7 +172,7 @@ typedef uintptr_t l_uintptr_t;
  * To use them on MacOS, which does not support these functions, set it to 0.
  *-------------------------------------------------------------------------*/
 #if !defined(HAVE_CONFIG_H) && !defined(ANDROID_BUILD) && !defined(OS_IOS) && \
-    !defined(_WIN32)
+    !defined(_WIN32) && !defined(__sun)
 #define  HAVE_FMEMOPEN    1
 #endif  /* ! HAVE_CONFIG_H etc. */
 
