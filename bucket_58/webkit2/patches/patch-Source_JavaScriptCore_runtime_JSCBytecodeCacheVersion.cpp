--- Source/JavaScriptCore/runtime/JSCBytecodeCacheVersion.cpp.orig	2025-08-11 07:56:48 UTC
+++ Source/JavaScriptCore/runtime/JSCBytecodeCacheVersion.cpp
@@ -42,6 +42,10 @@
 #endif
 #endif
 
+#if defined(__NetBSD__)
+#define NT_GNU_BUILD_ID 3
+#endif
+
 namespace JSC {
 
 namespace JSCBytecodeCacheVersionInternal {
