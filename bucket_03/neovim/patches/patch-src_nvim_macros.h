--- src/nvim/macros.h.orig	2018-06-10 22:46:49 UTC
+++ src/nvim/macros.h
@@ -156,7 +156,9 @@
 #define RGB_(r, g, b) ((r << 16) | (g << 8) | b)
 
 #define STR_(x) #x
+#ifndef __sun__
 #define STR(x) STR_(x)
+#endif
 
 #ifndef __has_attribute
 # define NVIM_HAS_ATTRIBUTE(x) 0
