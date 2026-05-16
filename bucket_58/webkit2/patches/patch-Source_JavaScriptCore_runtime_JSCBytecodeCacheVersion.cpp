--- Source/JavaScriptCore/runtime/JSCBytecodeCacheVersion.cpp.orig	2026-02-23 14:40:52 UTC
+++ Source/JavaScriptCore/runtime/JSCBytecodeCacheVersion.cpp
@@ -44,6 +44,10 @@
 #endif
 #endif
 
+#if defined(__NetBSD__) || defined(__sun)
+#define NT_GNU_BUILD_ID 3
+#endif
+
 namespace JSC {
 
 namespace JSCBytecodeCacheVersionInternal {
