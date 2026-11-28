--- modules/dnn/src/int8layers/elementwise_layers.cpp.orig	2026-11-05 11:18:05 UTC
+++ modules/dnn/src/int8layers/elementwise_layers.cpp
@@ -135,7 +135,7 @@ public:
                                       table[srcptr[i+4] + 128], table[srcptr[i+5] + 128], table[srcptr[i+6] + 128], table[srcptr[i+7] + 128],
                                       table[srcptr[i+8] + 128], table[srcptr[i+9] + 128], table[srcptr[i+10] + 128], table[srcptr[i+11] + 128],
                                       table[srcptr[i+12] + 128], table[srcptr[i+13] + 128], table[srcptr[i+14] + 128], table[srcptr[i+15] + 128]);
-                        v_store(dstptr + i, out);
+                        v_store((schar*)dstptr + i, out);
                     }
 #endif
                     for( ; i < len; i++ )
@@ -344,7 +344,7 @@ public:
                               lut[src[i+4] + 128], lut[src[i+5] + 128], lut[src[i+6] + 128], lut[src[i+7] + 128],
                               lut[src[i+8] + 128], lut[src[i+9] + 128], lut[src[i+10] + 128], lut[src[i+11] + 128],
                               lut[src[i+12] + 128], lut[src[i+13] + 128], lut[src[i+14] + 128], lut[src[i+15] + 128]);
-                v_store(dst + i, out);
+                v_store((schar*)dst + i, out);
             }
 #endif
             for( ; i < len; i++ )
