Needed for INT_MAX on sunos

--- 3rdparty/protobuf/src/google/protobuf/message_lite.cc.orig	2017-12-22 19:46:21 UTC
+++ 3rdparty/protobuf/src/google/protobuf/message_lite.cc
@@ -38,6 +38,7 @@
 #include <google/protobuf/message_lite.h>
 #include <google/protobuf/repeated_field.h>
 #include <string>
+#include <climits>
 #include <google/protobuf/stubs/logging.h>
 #include <google/protobuf/stubs/common.h>
 #include <google/protobuf/io/coded_stream.h>
