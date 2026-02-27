--- ../mod_zip-1.3.0/ngx_http_zip_endian.h.orig	2023-02-20 14:14:37 UTC
+++ ../mod_zip-1.3.0/ngx_http_zip_endian.h
@@ -7,7 +7,7 @@
 
 #endif
 
-#if defined(__linux__) || defined(__CYGWIN__)
+#if defined(__linux__) || defined(__CYGWIN__) || defined(__sun__)
 
 #	include <endian.h>
 
