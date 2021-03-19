--- libgnucash/engine/gnc-numeric.cpp.orig	2020-12-27 19:35:55 UTC
+++ libgnucash/engine/gnc-numeric.cpp
@@ -22,11 +22,11 @@
  *                                                                  *
  *******************************************************************/
 
+#include <glib.h>
 extern "C"
 {
 #include <config.h>
 
-#include <glib.h>
 #include <math.h>
 #include <stdio.h>
 #include <stdlib.h>
