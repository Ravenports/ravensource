--- fec_imp.h.orig	2005-03-03 16:56:45 UTC
+++ fec_imp.h
@@ -205,7 +205,7 @@ init_mul_table()
 }
 #else	/* GF_BITS > 8 */
 static inline gf
-gf_mul(x,y)
+gf_mul(int x, int y)
 {
     if ( (x) == 0 || (y)==0 ) return 0;
      
