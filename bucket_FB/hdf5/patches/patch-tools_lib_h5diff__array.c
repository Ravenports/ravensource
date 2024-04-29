--- tools/lib/h5diff_array.c.orig	2024-04-15 19:47:31 UTC
+++ tools/lib/h5diff_array.c
@@ -1718,8 +1718,8 @@ diff_float_element(unsigned char *mem1,
          *-------------------------------------------------------------------------
          */
         if (opts->do_nans) {
-            isnan1 = isnan(temp1_float);
-            isnan2 = isnan(temp2_float);
+            isnan1 = __builtin_isnan(temp1_float);
+            isnan2 = __builtin_isnan(temp2_float);
         }
 
         /* both not NaN, do the comparison */
@@ -1755,8 +1755,8 @@ diff_float_element(unsigned char *mem1,
          *-------------------------------------------------------------------------
          */
         if (opts->do_nans) {
-            isnan1 = isnan(temp1_float);
-            isnan2 = isnan(temp2_float);
+            isnan1 = __builtin_isnan(temp1_float);
+            isnan2 = __builtin_isnan(temp2_float);
         }
         /* both not NaN, do the comparison */
         if ((!isnan1 && !isnan2)) {
@@ -1803,8 +1803,8 @@ diff_float_element(unsigned char *mem1,
          *-------------------------------------------------------------------------
          */
         if (opts->do_nans) {
-            isnan1 = isnan(temp1_float);
-            isnan2 = isnan(temp2_float);
+            isnan1 = __builtin_isnan(temp1_float);
+            isnan2 = __builtin_isnan(temp2_float);
         }
 
         /* both not NaN, do the comparison */
@@ -1896,8 +1896,8 @@ diff_double_element(unsigned char *mem1,
          *-------------------------------------------------------------------------
          */
         if (opts->do_nans) {
-            isnan1 = isnan(temp1_double);
-            isnan2 = isnan(temp2_double);
+            isnan1 = __builtin_isnan(temp1_double);
+            isnan2 = __builtin_isnan(temp2_double);
         }
 
         /* both not NaN, do the comparison */
@@ -1932,8 +1932,8 @@ diff_double_element(unsigned char *mem1,
          *-------------------------------------------------------------------------
          */
         if (opts->do_nans) {
-            isnan1 = isnan(temp1_double);
-            isnan2 = isnan(temp2_double);
+            isnan1 = __builtin_isnan(temp1_double);
+            isnan2 = __builtin_isnan(temp2_double);
         }
         /* both not NaN, do the comparison */
         if (!isnan1 && !isnan2) {
@@ -1978,8 +1978,8 @@ diff_double_element(unsigned char *mem1,
          *-------------------------------------------------------------------------
          */
         if (opts->do_nans) {
-            isnan1 = isnan(temp1_double);
-            isnan2 = isnan(temp2_double);
+            isnan1 = __builtin_isnan(temp1_double);
+            isnan2 = __builtin_isnan(temp2_double);
         }
 
         /* both not NaN, do the comparison */
@@ -2071,8 +2071,8 @@ diff_ldouble_element(unsigned char *mem1
          *-------------------------------------------------------------------------
          */
         if (opts->do_nans) {
-            isnan1 = isnan(temp1_double);
-            isnan2 = isnan(temp2_double);
+            isnan1 = __builtin_isnan(temp1_double);
+            isnan2 = __builtin_isnan(temp2_double);
         }
 
         /* both not NaN, do the comparison */
@@ -2106,8 +2106,8 @@ diff_ldouble_element(unsigned char *mem1
          *-------------------------------------------------------------------------
          */
         if (opts->do_nans) {
-            isnan1 = isnan(temp1_double);
-            isnan2 = isnan(temp2_double);
+            isnan1 = __builtin_isnan(temp1_double);
+            isnan2 = __builtin_isnan(temp2_double);
         }
 
         /* both not NaN, do the comparison */
@@ -2153,8 +2153,8 @@ diff_ldouble_element(unsigned char *mem1
          *-------------------------------------------------------------------------
          */
         if (opts->do_nans) {
-            isnan1 = isnan(temp1_double);
-            isnan2 = isnan(temp2_double);
+            isnan1 = __builtin_isnan(temp1_double);
+            isnan2 = __builtin_isnan(temp2_double);
         }
 
         /* both not NaN, do the comparison */
@@ -2246,8 +2246,8 @@ diff_float16_element(unsigned char *mem1
          *-------------------------------------------------------------------------
          */
         if (opts->do_nans) {
-            isnan1 = isnan(temp1_float16);
-            isnan2 = isnan(temp2_float16);
+            isnan1 = __builtin_isnan(temp1_float16);
+            isnan2 = __builtin_isnan(temp2_float16);
         }
 
         /* both not NaN, do the comparison */
@@ -2283,8 +2283,8 @@ diff_float16_element(unsigned char *mem1
          *-------------------------------------------------------------------------
          */
         if (opts->do_nans) {
-            isnan1 = isnan(temp1_float16);
-            isnan2 = isnan(temp2_float16);
+            isnan1 = __builtin_isnan(temp1_float16);
+            isnan2 = __builtin_isnan(temp2_float16);
         }
         /* both not NaN, do the comparison */
         if ((!isnan1 && !isnan2)) {
@@ -2331,8 +2331,8 @@ diff_float16_element(unsigned char *mem1
          *-------------------------------------------------------------------------
          */
         if (opts->do_nans) {
-            isnan1 = isnan(temp1_float16);
-            isnan2 = isnan(temp2_float16);
+            isnan1 = __builtin_isnan(temp1_float16);
+            isnan2 = __builtin_isnan(temp2_float16);
         }
 
         /* both not NaN, do the comparison */
@@ -3353,8 +3353,8 @@ equal_double(double value, double expect
          * detect NaNs
          *-------------------------------------------------------------------------
          */
-        bool isnan1 = isnan(value);
-        bool isnan2 = isnan(expected);
+        bool isnan1 = __builtin_isnan(value);
+        bool isnan2 = __builtin_isnan(expected);
 
         /*-------------------------------------------------------------------------
          * we consider NaN == NaN to be true
@@ -3400,8 +3400,8 @@ equal_ldouble(long double value, long do
          * detect NaNs
          *-------------------------------------------------------------------------
          */
-        bool isnan1 = isnan(value);
-        bool isnan2 = isnan(expected);
+        bool isnan1 = __builtin_isnan(value);
+        bool isnan2 = __builtin_isnan(expected);
 
         /*-------------------------------------------------------------------------
          * we consider NaN == NaN to be true
@@ -3446,8 +3446,8 @@ equal_float(float value, float expected,
          * detect NaNs
          *-------------------------------------------------------------------------
          */
-        bool isnan1 = isnan(value);
-        bool isnan2 = isnan(expected);
+        bool isnan1 = __builtin_isnan(value);
+        bool isnan2 = __builtin_isnan(expected);
 
         /*-------------------------------------------------------------------------
          * we consider NaN == NaN to be true
