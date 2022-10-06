--- src/nvim/macros.h.orig	2022-09-30 15:15:13 UTC
+++ src/nvim/macros.h
@@ -137,7 +137,9 @@
 #define RGB_(r, g, b) (((r) << 16) | ((g) << 8) | (b))
 
 #define STR_(x) #x
+#ifndef __sun__
 #define STR(x) STR_(x)
+#endif
 
 #ifndef __has_include
 # define NVIM_HAS_INCLUDE(x) 0
