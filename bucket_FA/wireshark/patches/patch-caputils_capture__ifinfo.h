--- caputils/capture_ifinfo.h.orig	2021-03-10 18:21:20 UTC
+++ caputils/capture_ifinfo.h
@@ -11,12 +11,12 @@
 #ifndef __CAPTURE_IFINFO_H__
 #define __CAPTURE_IFINFO_H__
 
+#include <glib.h>
+
 #ifdef __cplusplus
 extern "C" {
 #endif /* __cplusplus */
 
-#include <glib.h>
-
 /*
  * Explicitly set the interface_type enum values as these values are exposed
  * in the preferences gui.interfaces_hidden_types string.
