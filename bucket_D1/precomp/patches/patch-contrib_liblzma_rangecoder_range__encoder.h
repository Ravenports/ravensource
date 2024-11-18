--- contrib/liblzma/rangecoder/range_encoder.h.orig	2019-02-22 14:12:14 UTC
+++ contrib/liblzma/rangecoder/range_encoder.h
@@ -14,6 +14,7 @@
 #ifndef LZMA_RANGE_ENCODER_H
 #define LZMA_RANGE_ENCODER_H
 
+#include <assert.h>
 #include "range_common.h"
 #include "price.h"
 
