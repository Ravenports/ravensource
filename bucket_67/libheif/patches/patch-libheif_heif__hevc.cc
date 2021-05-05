--- libheif/heif_hevc.cc.orig	2021-05-05 07:15:29 UTC
+++ libheif/heif_hevc.cc
@@ -45,10 +45,10 @@ static double read_depth_rep_info_elemen
   //printf("sign:%d exponent:%d mantissa_len:%d mantissa:%d\n",sign_flag,exponent,mantissa_len,mantissa);
 
   if (exponent > 0) {
-    value = pow(2, exponent - 31) * (1.0 + mantissa / pow(2, mantissa_len));
+    value = pow(2.0, exponent - 31) * (1.0 + mantissa / pow(2.0, mantissa_len));
   }
   else {
-    value = pow(2, -(30 + mantissa_len)) * mantissa;
+    value = pow(2.0, -(30 + mantissa_len)) * mantissa;
   }
 
   if (sign_flag) {
