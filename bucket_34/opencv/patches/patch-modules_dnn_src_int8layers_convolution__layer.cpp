--- modules/dnn/src/int8layers/convolution_layer.cpp.orig	2025-12-30 07:52:05 UTC
+++ modules/dnn/src/int8layers/convolution_layer.cpp
@@ -1050,15 +1050,15 @@ public:
                                                 out_j = outW1 - out_delta;
                                             }
                                             int in_j = out_j * stride_w - pad_l;
-                                            v_int8x16 v00 = v_load(imgptr0 + in_j),
-                                                      v01 = v_load(imgptr0 + in_j + dilation_w),
-                                                      v02 = v_load(imgptr0 + in_j + dilation_w*2),
-                                                      v10 = v_load(imgptr1 + in_j),
-                                                      v11 = v_load(imgptr1 + in_j + dilation_w),
-                                                      v12 = v_load(imgptr1 + in_j + dilation_w*2),
-                                                      v20 = v_load(imgptr2 + in_j),
-                                                      v21 = v_load(imgptr2 + in_j + dilation_w),
-                                                      v22 = v_load(imgptr2 + in_j + dilation_w*2);
+                                            v_int8x16 v00 = v_load((const schar*)imgptr0 + in_j),
+                                                      v01 = v_load((const schar*)imgptr0 + in_j + dilation_w),
+                                                      v02 = v_load((const schar*)imgptr0 + in_j + dilation_w*2),
+                                                      v10 = v_load((const schar*)imgptr1 + in_j),
+                                                      v11 = v_load((const schar*)imgptr1 + in_j + dilation_w),
+                                                      v12 = v_load((const schar*)imgptr1 + in_j + dilation_w*2),
+                                                      v20 = v_load((const schar*)imgptr2 + in_j),
+                                                      v21 = v_load((const schar*)imgptr2 + in_j + dilation_w),
+                                                      v22 = v_load((const schar*)imgptr2 + in_j + dilation_w*2);
 
                                             vout0 = vout1 = vout2 = vout3 = vbias;
                                             v_expand_mul_add(v00, vw00, vout0, vout1, vout2, vout3);
@@ -1419,12 +1419,12 @@ public:
                                           vs12 = v_setzero_s32(), vs13 = v_setzero_s32();
                                 for( k = 0; k < vsz; k += 16, rptr += 16 )
                                 {
-                                    v_int8x16 w0 = v_load_aligned(wptr0 + k);
-                                    v_int8x16 w1 = v_load_aligned(wptr1 + k);
-                                    v_int8x16 r0 = v_load_aligned(rptr);
-                                    v_int8x16 r1 = v_load_aligned(rptr + vsz_a);
-                                    v_int8x16 r2 = v_load_aligned(rptr + vsz_a*2);
-                                    v_int8x16 r3 = v_load_aligned(rptr + vsz_a*3);
+                                    v_int8x16 w0 = v_load_aligned((const schar*)wptr0 + k);
+                                    v_int8x16 w1 = v_load_aligned((const schar*)wptr1 + k);
+                                    v_int8x16 r0 = v_load_aligned((const schar*)rptr);
+                                    v_int8x16 r1 = v_load_aligned((const schar*)rptr + vsz_a);
+                                    v_int8x16 r2 = v_load_aligned((const schar*)rptr + vsz_a*2);
+                                    v_int8x16 r3 = v_load_aligned((const schar*)rptr + vsz_a*3);
 
                                     vs00 = v_dotprod_expand_fast(w0, r0, vs00);
                                     vs01 = v_dotprod_expand_fast(w0, r1, vs01);
