--- src/compression.c.orig	2025-03-13 13:44:37 UTC
+++ src/compression.c
@@ -19,6 +19,10 @@
 
 #include "common.h"
 
+#ifndef EBADFD
+#define EBADFD EBADF
+#endif
+
 #ifndef STROPHE_COMPRESSION_BUFFER_SIZE
 /** Max buffer size for compressed data (send & receive). */
 #define STROPHE_COMPRESSION_BUFFER_SIZE 4096
