--- ../src/google/protobuf/port_def.inc.orig	2021-04-07 22:38:38 UTC
+++ ../src/google/protobuf/port_def.inc
@@ -587,7 +587,7 @@
 #define PROTOBUF_ATTRIBUTE_NO_DESTROY
 #endif
 
-#if defined(__GNUC__)
+#if defined(__GNUC__) && !defined(__sun__)
 // Protobuf extensions and reflection require registration of the protos linked
 // in the binary. Not until everything is registered does the runtime have a
 // complete view on all protos. When code is using reflection or extensions
