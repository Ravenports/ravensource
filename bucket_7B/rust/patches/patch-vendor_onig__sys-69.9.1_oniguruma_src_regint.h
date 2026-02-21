--- vendor/onig_sys-69.9.1/oniguruma/src/regint.h.orig	2026-02-11 07:30:54 UTC
+++ vendor/onig_sys-69.9.1/oniguruma/src/regint.h
@@ -268,7 +268,7 @@
 #else
 
 #ifndef xalloca
-#define xalloca  alloca
+#define xalloca  __builtin_alloca
 #endif
 #ifndef xvsnprintf
 #define xvsnprintf  vsnprintf
