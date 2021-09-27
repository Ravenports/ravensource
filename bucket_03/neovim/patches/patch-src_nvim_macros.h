--- src/nvim/macros.h.orig	2021-09-26 22:15:30 UTC
+++ src/nvim/macros.h
@@ -147,7 +147,9 @@
 #define RGB_(r, g, b) ((r << 16) | (g << 8) | b)
 
 #define STR_(x) #x
+#ifndef __sun__
 #define STR(x) STR_(x)
+#endif
 
 #ifndef __has_include
 # define NVIM_HAS_INCLUDE(x) 0
