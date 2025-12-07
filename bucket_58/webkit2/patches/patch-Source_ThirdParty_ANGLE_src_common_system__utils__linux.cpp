--- Source/ThirdParty/ANGLE/src/common/system_utils_linux.cpp.orig	2025-11-07 13:21:47 UTC
+++ Source/ThirdParty/ANGLE/src/common/system_utils_linux.cpp
@@ -59,6 +59,10 @@ void SetCurrentThreadName(const char *na
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
