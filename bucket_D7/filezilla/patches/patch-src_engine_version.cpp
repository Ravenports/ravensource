--- src/engine/version.cpp.orig	2025-09-26 03:30:01 UTC
+++ src/engine/version.cpp
@@ -159,7 +159,11 @@ SystemVersion GetSystemVersion()
 SystemVersion GetSystemVersion()
 {
 	SystemVersion ret;
+#if defined(__sun__)
+	struct utsname buf{};
+#else
 	utsname buf{};
+#endif
 	if (!uname(&buf)) {
 		char const* p = buf.release;
 		while (*p >= '0' && *p <= '9') {
