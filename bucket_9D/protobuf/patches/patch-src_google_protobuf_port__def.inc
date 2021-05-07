--- ../src/google/protobuf/port_def.inc.orig	2021-05-06 19:50:11 UTC
+++ ../src/google/protobuf/port_def.inc
@@ -589,7 +589,7 @@
 #define PROTOBUF_ATTRIBUTE_NO_DESTROY
 #endif
 
-#if defined(__GNUC__)
+#if defined(__GNUC__) && !defined(__sun__)
 // Protobuf extensions and reflection require registration of the protos linked
 // in the binary. Not until everything is registered does the runtime have a
 // complete view on all protos. When code is using reflection or extensions
