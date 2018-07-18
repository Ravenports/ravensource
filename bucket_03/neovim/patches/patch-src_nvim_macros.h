--- src/nvim/macros.h.orig	2018-07-18 11:44:59 UTC
+++ src/nvim/macros.h
@@ -150,7 +150,9 @@
 #define RGB_(r, g, b) ((r << 16) | (g << 8) | b)
 
 #define STR_(x) #x
+#ifndef __sun__
 #define STR(x) STR_(x)
+#endif
 
 #ifndef __has_attribute
 # define NVIM_HAS_ATTRIBUTE(x) 0
