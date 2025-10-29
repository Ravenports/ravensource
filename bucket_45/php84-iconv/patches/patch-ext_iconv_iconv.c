--- iconv.c.orig	2025-09-23 14:14:32 UTC
+++ iconv.c
@@ -43,7 +43,7 @@
 #undef iconv
 #endif
 
-#if defined(__NetBSD__)
+#if 0
 // unfortunately, netbsd has still the old non posix conformant signature
 // libiconv tends to match the eventual system's iconv too.
 #define ICONV_CONST const
