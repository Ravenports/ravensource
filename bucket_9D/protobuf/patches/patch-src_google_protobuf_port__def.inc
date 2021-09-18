$NetBSD: patch-src_google_protobuf_port__def.inc,v 1.3 2021/06/09 04:57:10 adam Exp $

SunOS does not support init_priority.

--- ../src/google/protobuf/port_def.inc.orig	2021-09-14 16:48:28 UTC
+++ ../src/google/protobuf/port_def.inc
@@ -590,7 +590,7 @@
 #ifdef PROTOBUF_ATTRIBUTE_INIT_PRIORITY
 #error PROTOBUF_ATTRIBUTE_INIT_PRIORITY was previously defined
 #endif
-#if PROTOBUF_GNUC_MIN(3, 0) && (!defined(__APPLE__) || defined(__clang__))
+#if PROTOBUF_GNUC_MIN(3, 0) && !defined(__sun) && (!defined(__APPLE__) || defined(__clang__))
 #define PROTOBUF_ATTRIBUTE_INIT_PRIORITY __attribute__((init_priority((102))))
 #else
 #define PROTOBUF_ATTRIBUTE_INIT_PRIORITY
