--- lib/type1/objects.c.orig	2007-12-23 16:49:42.000000000 +0100
+++ lib/type1/objects.c	2019-06-06 15:23:45.191036000 +0200
@@ -1137,12 +1137,13 @@
     "Context:  out of them", /* 46 */
     "MatrixInvert:  can't", /* 47 */
     "xiStub called", /* 48 */
-    "Illegal access type1 abort() message" /* 49 */
+    "Lines this big not supported", /* 49 */
+    "Illegal access type1 abort() message" /* 50 */
   };
 
-  /* no is valid from 1 to 48 */
-  if ( (number<1)||(number>48))
-    number=49;
+  /* no is valid from 1 to 49 */
+  if ( (number<1)||(number>49))
+    number=50;
   return( err_msgs[number-1]);
     
 }
