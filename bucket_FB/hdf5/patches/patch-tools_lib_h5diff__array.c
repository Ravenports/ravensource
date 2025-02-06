--- tools/lib/h5diff_array.c.orig	2025-02-05 14:11:32 UTC
+++ tools/lib/h5diff_array.c
@@ -1719,8 +1719,8 @@ diff_float_element(unsigned char *mem1,
          *-------------------------------------------------------------------------
          */
         if (opts->do_nans) {
-            isnan1 = isnan(temp1_float);
-            isnan2 = isnan(temp2_float);
+            isnan1 = __builtin_isnan(temp1_float);
+            isnan2 = __builtin_isnan(temp2_float);
         }
 
         /* both not NaN, do the comparison */
@@ -1756,8 +1756,8 @@ diff_float_element(unsigned char *mem1,
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
@@ -1804,8 +1804,8 @@ diff_float_element(unsigned char *mem1,
          *-------------------------------------------------------------------------
          */
         if (opts->do_nans) {
-            isnan1 = isnan(temp1_float);
-            isnan2 = isnan(temp2_float);
+            isnan1 = __builtin_isnan(temp1_float);
+            isnan2 = __builtin_isnan(temp2_float);
         }
 
         /* both not NaN, do the comparison */
@@ -1897,8 +1897,8 @@ diff_double_element(unsigned char *mem1,
          *-------------------------------------------------------------------------
          */
         if (opts->do_nans) {
-            isnan1 = isnan(temp1_double);
-            isnan2 = isnan(temp2_double);
+            isnan1 = __builtin_isnan(temp1_double);
+            isnan2 = __builtin_isnan(temp2_double);
         }
 
         /* both not NaN, do the comparison */
@@ -1933,8 +1933,8 @@ diff_double_element(unsigned char *mem1,
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
@@ -1979,8 +1979,8 @@ diff_double_element(unsigned char *mem1,
          *-------------------------------------------------------------------------
          */
         if (opts->do_nans) {
-            isnan1 = isnan(temp1_double);
-            isnan2 = isnan(temp2_double);
+            isnan1 = __builtin_isnan(temp1_double);
+            isnan2 = __builtin_isnan(temp2_double);
         }
 
         /* both not NaN, do the comparison */
@@ -2072,8 +2072,8 @@ diff_ldouble_element(unsigned char *mem1
          *-------------------------------------------------------------------------
          */
         if (opts->do_nans) {
-            isnan1 = isnan(temp1_double);
-            isnan2 = isnan(temp2_double);
+            isnan1 = __builtin_isnan(temp1_double);
+            isnan2 = __builtin_isnan(temp2_double);
         }
 
         /* both not NaN, do the comparison */
@@ -2107,8 +2107,8 @@ diff_ldouble_element(unsigned char *mem1
          *-------------------------------------------------------------------------
          */
         if (opts->do_nans) {
-            isnan1 = isnan(temp1_double);
-            isnan2 = isnan(temp2_double);
+            isnan1 = __builtin_isnan(temp1_double);
+            isnan2 = __builtin_isnan(temp2_double);
         }
 
         /* both not NaN, do the comparison */
@@ -2154,8 +2154,8 @@ diff_ldouble_element(unsigned char *mem1
          *-------------------------------------------------------------------------
          */
         if (opts->do_nans) {
-            isnan1 = isnan(temp1_double);
-            isnan2 = isnan(temp2_double);
+            isnan1 = __builtin_isnan(temp1_double);
+            isnan2 = __builtin_isnan(temp2_double);
         }
 
         /* both not NaN, do the comparison */
@@ -2247,8 +2247,8 @@ diff_float16_element(unsigned char *mem1
          *-------------------------------------------------------------------------
          */
         if (opts->do_nans) {
-            isnan1 = isnan(temp1_float16);
-            isnan2 = isnan(temp2_float16);
+            isnan1 = __builtin_isnan(temp1_float16);
+            isnan2 = __builtin_isnan(temp2_float16);
         }
 
         /* both not NaN, do the comparison */
@@ -2284,8 +2284,8 @@ diff_float16_element(unsigned char *mem1
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
@@ -2332,8 +2332,8 @@ diff_float16_element(unsigned char *mem1
          *-------------------------------------------------------------------------
          */
         if (opts->do_nans) {
-            isnan1 = isnan(temp1_float16);
-            isnan2 = isnan(temp2_float16);
+            isnan1 = __builtin_isnan(temp1_float16);
+            isnan2 = __builtin_isnan(temp2_float16);
         }
 
         /* both not NaN, do the comparison */
@@ -3354,8 +3354,8 @@ equal_double(double value, double expect
          * detect NaNs
          *-------------------------------------------------------------------------
          */
-        bool isnan1 = isnan(value);
-        bool isnan2 = isnan(expected);
+        bool isnan1 = __builtin_isnan(value);
+        bool isnan2 = __builtin_isnan(expected);
 
         /*-------------------------------------------------------------------------
          * we consider NaN == NaN to be true
@@ -3401,8 +3401,8 @@ equal_ldouble(long double value, long do
          * detect NaNs
          *-------------------------------------------------------------------------
          */
-        bool isnan1 = isnan(value);
-        bool isnan2 = isnan(expected);
+        bool isnan1 = __builtin_isnan(value);
+        bool isnan2 = __builtin_isnan(expected);
 
         /*-------------------------------------------------------------------------
          * we consider NaN == NaN to be true
@@ -3447,8 +3447,8 @@ equal_float(float value, float expected,
          * detect NaNs
          *-------------------------------------------------------------------------
          */
-        bool isnan1 = isnan(value);
-        bool isnan2 = isnan(expected);
+        bool isnan1 = __builtin_isnan(value);
+        bool isnan2 = __builtin_isnan(expected);
 
         /*-------------------------------------------------------------------------
          * we consider NaN == NaN to be true
