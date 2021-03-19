--- epan/prefs.h.orig	2021-03-10 18:21:20 UTC
+++ epan/prefs.h
@@ -11,12 +11,12 @@
 #ifndef __PREFS_H__
 #define __PREFS_H__
 
+#include <glib.h>
+
 #ifdef __cplusplus
 extern "C" {
 #endif /* __cplusplus */
 
-#include <glib.h>
-
 #include <epan/params.h>
 #include <epan/range.h>
 
