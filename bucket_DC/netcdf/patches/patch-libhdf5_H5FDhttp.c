--- libhdf5/H5FDhttp.c.orig	2025-02-07 21:40:00 UTC
+++ libhdf5/H5FDhttp.c
@@ -49,14 +49,6 @@
 Define a simple #ifdef test for the version of H5FD_class_t we are using 
 */
 
-#if H5_VERS_MAJOR == 1
-#if H5_VERS_MINOR < 10
-#define H5FDCLASS1 1
-#endif
-#else
-#error "Cannot determine version of H5FD_class_t"
-#endif
-
 #ifdef H5_HAVE_WIN32_API
 /* The following two defines must be before any windows headers are included */
 #define WIN32_LEAN_AND_MEAN    /* Exclude rarely-used stuff from Windows headers */
