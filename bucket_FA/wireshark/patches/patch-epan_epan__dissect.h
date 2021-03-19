--- epan/epan_dissect.h.orig	2021-03-10 18:21:20 UTC
+++ epan/epan_dissect.h
@@ -10,11 +10,11 @@
 #ifndef EPAN_DISSECT_H
 #define EPAN_DISSECT_H
 
+#include "epan.h"
 #ifdef __cplusplus
 extern "C" {
 #endif /* __cplusplus */
 
-#include "epan.h"
 #include "tvbuff.h"
 #include "proto.h"
 #include "packet_info.h"
