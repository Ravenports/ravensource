--- Source/ThirdParty/ANGLE/src/common/system_utils_linux.cpp.orig	2024-03-16 06:45:47 UTC
+++ Source/ThirdParty/ANGLE/src/common/system_utils_linux.cpp
@@ -56,6 +56,10 @@ void SetCurrentThreadName(const char *na
 {
     // There's a 15-character (16 including '\0') limit.  If the name is too big (and ERANGE is
     // returned), just ignore the name.
+#if defined(__NetBSD__)
+    pthread_setname_np(pthread_self(), "%s", (void *)name);
+#else
     pthread_setname_np(pthread_self(), name);
+#endif
 }
 }  // namespace angle
