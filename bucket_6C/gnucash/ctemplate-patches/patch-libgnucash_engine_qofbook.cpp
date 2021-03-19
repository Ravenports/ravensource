--- libgnucash/engine/qofbook.cpp.orig	2020-09-27 18:52:46 UTC
+++ libgnucash/engine/qofbook.cpp
@@ -33,15 +33,15 @@
  * Copyright (c) 2007 David Hampton <hampton@employees.org>
  */
 
+#include <config.h>
+#include <glib.h>
 extern "C"
 {
 
-#include <config.h>
 
 #include <stdlib.h>
 #include <string.h>
 
-#include <glib.h>
 #ifdef GNC_PLATFORM_WINDOWS
   /* Mingw disables the standard type macros for C++ without this override. */
 #define __STDC_FORMAT_MACROS = 1
