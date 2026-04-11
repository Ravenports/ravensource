--- modules/dnn/src/int8layers/fully_connected_layer.cpp.orig	2025-12-30 07:52:05 UTC
+++ modules/dnn/src/int8layers/fully_connected_layer.cpp
@@ -327,11 +327,11 @@ public:
 
                         for( k = 0; k < vecsize; k += 16 )
                         {
-                            v_int8x16 v = v_load_aligned(sptr + k);
-                            vs0 = v_dotprod_expand_fast(v, v_load_aligned(wptr + k), vs0);
-                            vs1 = v_dotprod_expand_fast(v, v_load_aligned(wptr + wstep + k), vs1);
-                            vs2 = v_dotprod_expand_fast(v, v_load_aligned(wptr + wstep*2 + k), vs2);
-                            vs3 = v_dotprod_expand_fast(v, v_load_aligned(wptr + wstep*3 + k), vs3);
+                            v_int8x16 v = v_load_aligned((const schar*)sptr + k);
+                            vs0 = v_dotprod_expand_fast(v, v_load_aligned((const schar*)wptr + k), vs0);
+                            vs1 = v_dotprod_expand_fast(v, v_load_aligned((const schar*)wptr + wstep + k), vs1);
+                            vs2 = v_dotprod_expand_fast(v, v_load_aligned((const schar*)wptr + wstep*2 + k), vs2);
+                            vs3 = v_dotprod_expand_fast(v, v_load_aligned((const schar*)wptr + wstep*3 + k), vs3);
                         }
 
                         s = v_add(s, v_int32x4(v_reduce_sum(vs0), v_reduce_sum(vs1), v_reduce_sum(vs2), v_reduce_sum(vs3)));
