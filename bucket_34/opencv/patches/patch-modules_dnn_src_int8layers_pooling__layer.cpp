--- modules/dnn/src/int8layers/pooling_layer.cpp.orig	2025-12-30 07:52:05 UTC
+++ modules/dnn/src/int8layers/pooling_layer.cpp
@@ -519,7 +519,7 @@ public:
                                     for (int k = 0; k < kernel_w*kernel_h; k++)
                                     {
                                         int index = ofsptr[k];
-                                        v_int8x16 v0 = v_load(srcData1 + index);
+                                        v_int8x16 v0 = v_load((const schar*)srcData1 + index);
                                         max_val0 = v_max(max_val0, v0);
                                     }
                                 else if( stride_w == 2 )
@@ -527,7 +527,7 @@ public:
                                     {
                                         int index = ofsptr[k];
                                         v_int8x16 v0, dummy;
-                                        v_load_deinterleave(srcData1 + index, v0, dummy);
+                                        v_load_deinterleave((const schar*)srcData1 + index, v0, dummy);
                                         max_val0 = v_max(max_val0, v0);
                                     }
                                 else
@@ -564,7 +564,7 @@ public:
                                     }
                                 }
                             }
-                            v_store(dstData + x0, max_val0);
+                            v_store((schar *)dstData + x0, max_val0);
                             x0 += 15;
                         }
                         else
@@ -644,7 +644,7 @@ public:
                             sum_val2 = v_add(v_round(v_mul(v_cvt_f32(sum_val2), ikarea)), voutzp);
                             sum_val3 = v_add(v_round(v_mul(v_cvt_f32(sum_val3), ikarea)), voutzp);
 
-                            v_store(dstData + x0, v_pack(v_pack(sum_val0, sum_val1), v_pack(sum_val2, sum_val3)));
+                            v_store((schar *)dstData + x0, v_pack(v_pack(sum_val0, sum_val1), v_pack(sum_val2, sum_val3)));
                             x0 += 15;
                         }
                         else
