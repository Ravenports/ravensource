--- libgnucash/core-utils/gnc-filepath-utils.cpp.orig	2020-09-27 18:52:46 UTC
+++ libgnucash/core-utils/gnc-filepath-utils.cpp
@@ -26,6 +26,11 @@
  * @author Copyright (c) 2000 Dave Peticolas
  */
 
+#include <glib.h>
+#include <glib/gi18n.h>
+#include <glib/gprintf.h>
+#include <glib/gstdio.h>
+
 extern "C" {
 #include <config.h>
 
@@ -35,11 +40,6 @@ extern "C" {
 #include <Shlobj.h>
 #endif
 
-#include <glib.h>
-#include <glib/gi18n.h>
-#include <glib/gprintf.h>
-#include <glib/gstdio.h>
-
 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
