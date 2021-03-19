--- ui/recent.h.orig	2021-03-10 18:21:20 UTC
+++ ui/recent.h
@@ -12,11 +12,11 @@
 #ifndef __RECENT_H__
 #define __RECENT_H__
 
+#include <glib.h>
 #ifdef __cplusplus
 extern "C" {
 #endif /* __cplusplus */
 
-#include <glib.h>
 #include <stdio.h>
 #include "epan/timestamp.h"
 #include "ui/ws_ui_util.h"
