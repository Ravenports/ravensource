--- util/env_posix.cc.orig	2021-02-23 20:54:37 UTC
+++ util/env_posix.cc
@@ -49,11 +49,11 @@ constexpr const int kDefaultMmapLimit =
 int g_mmap_limit = kDefaultMmapLimit;
 
 // Common flags defined for all posix open operations
-#if defined(HAVE_O_CLOEXEC)
+#if defined(O_CLOEXEC)
 constexpr const int kOpenBaseFlags = O_CLOEXEC;
 #else
 constexpr const int kOpenBaseFlags = 0;
-#endif  // defined(HAVE_O_CLOEXEC)
+#endif  // defined(O_CLOEXEC)
 
 constexpr const size_t kWritableFileBufferSize = 65536;
 
