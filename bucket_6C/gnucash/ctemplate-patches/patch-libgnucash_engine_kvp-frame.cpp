--- libgnucash/engine/kvp-frame.cpp.orig	2020-06-07 16:56:25 UTC
+++ libgnucash/engine/kvp-frame.cpp
@@ -22,11 +22,11 @@
  *                                                                  *
  ********************************************************************/
 
-extern "C"
-{
 #include <config.h>
 #include "qof.h"
 #include <glib.h>
+extern "C"
+{
 #include <stdarg.h>
 #include <stdio.h>
 #include <string.h>
