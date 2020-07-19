Needed for INT_MAX on sunos

--- 3rdparty/protobuf/src/google/protobuf/message_lite.cc.orig	2020-07-17 22:43:40 UTC
+++ 3rdparty/protobuf/src/google/protobuf/message_lite.cc
@@ -40,6 +40,7 @@
 #include <google/protobuf/message_lite.h>
 #include <google/protobuf/repeated_field.h>
 #include <string>
+#include <climits>
 #include <google/protobuf/stubs/logging.h>
 #include <google/protobuf/stubs/common.h>
 #include <google/protobuf/io/coded_stream.h>
