--- protolib/src/common/protoDispatcher.cpp.orig	2024-08-03 04:37:54 UTC
+++ protolib/src/common/protoDispatcher.cpp
@@ -60,6 +60,9 @@ const ProtoDispatcher::Descriptor ProtoD
 const ProtoDispatcher::Descriptor ProtoDispatcher::INVALID_DESCRIPTOR = -1;
 #endif  // if/else WIN32/UNIX
 
+#ifdef USE_TIMERFD
+#include <sys/timerfd.h>
+#endif
 
 ProtoDispatcher::Stream::Stream(Type theType)
  :  type(theType) 
