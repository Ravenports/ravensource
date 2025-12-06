--- modules/codec/opus_header.h.orig	2025-11-13 22:17:54 UTC
+++ modules/codec/opus_header.h
@@ -29,6 +29,7 @@
 #define OPUS_HEADER_H
 
 #include <stdint.h>
+#include <stddef.h>
 
 typedef struct {
     int version;
