--- epan/epan.h.orig	2021-03-10 18:21:20 UTC
+++ epan/epan.h
@@ -10,11 +10,11 @@
 #ifndef __EPAN_H__
 #define __EPAN_H__
 
+#include <glib.h>
 #ifdef __cplusplus
 extern "C" {
 #endif /* __cplusplus */
 
-#include <glib.h>
 #include <epan/tvbuff.h>
 #include <epan/prefs.h>
 #include <epan/frame_data.h>
