--- texk/web2c/luatexdir/luaffi/ffi.h.intermediate	2023-08-25 13:06:31 UTC
+++ texk/web2c/luatexdir/luaffi/ffi.h
@@ -42,7 +42,7 @@ extern "C" {
 #include <sys/mman.h>
 #endif
 
-#if ( defined( _WIN32) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__bsdi__) || defined(__DragonFly__))
+#if 0
 /* We should include something equivalent to */
 /* complex.h                                 */
 #else
