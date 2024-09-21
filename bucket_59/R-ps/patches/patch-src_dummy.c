--- src/dummy.c.orig	2024-09-12 08:59:22 UTC
+++ src/dummy.c
@@ -64,10 +64,8 @@ SEXP ps__memory_maps(SEXP p) { return ps
 
 /* Only implemented on macOS */
 #ifndef PS__MACOS
-#if defined(PS__WINDOWS) || defined(PS__LINUX)
 SEXP ps__list_apps(void) { return ps__dummy("ps__list_apps"); }
 #endif
-#endif
 
 /* All C functions called from R */
 #ifndef PS__MACOS
