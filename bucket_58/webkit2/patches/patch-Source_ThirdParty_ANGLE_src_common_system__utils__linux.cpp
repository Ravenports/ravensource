--- Source/ThirdParty/ANGLE/src/common/system_utils_linux.cpp.orig	2026-02-23 14:40:52 UTC
+++ Source/ThirdParty/ANGLE/src/common/system_utils_linux.cpp
@@ -63,6 +63,10 @@ void SetCurrentThreadName(const char *na
     // There's a 15-character (16 including '\0') limit.  If the name is too big (and ERANGE is
     // returned), name will be ignored.
     ASSERT(strlen(name) < 16);
+#if defined(__NetBSD__)
+    pthread_setname_np(pthread_self(), "%s", (void *)name);
+#else
     pthread_setname_np(pthread_self(), name);
+#endif
 }
 }  // namespace angle
