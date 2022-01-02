--- filesystem/filesystem.hpp.orig	2021-12-12 11:59:45 UTC
+++ filesystem/filesystem.hpp
@@ -56,6 +56,9 @@
 #define GHC_OS_MACOS
 #elif defined(__linux__)
 #define GHC_OS_LINUX
+#elif defined(__sun)
+#define GHC_OS_SUNOS
+#define GHC_NO_DIRENT_D_TYPE
 #if defined(__ANDROID__)
 #define GHC_OS_ANDROID
 #endif
@@ -4483,6 +4486,20 @@ GHC_INLINE void last_write_time(const pa
     if (!::SetFileTime(file.get(), 0, 0, &ft)) {
         ec = detail::make_system_error();
     }
+#elif defined(GHC_OS_SUNOS)
+    struct ::stat fs;
+    if (::stat(p.c_str(), &fs) == 0) {
+        struct ::timeval tv[2];
+        tv[0].tv_sec = fs.st_atim.tv_sec;
+        tv[0].tv_usec = static_cast<int>(fs.st_atim.tv_nsec / 1000);
+        tv[1].tv_sec = std::chrono::duration_cast<std::chrono::seconds>(d).count();
+        tv[1].tv_usec = static_cast<int>(std::chrono::duration_cast<std::chrono::microseconds>(d).count() % 1000000);
+        if (::utimes(p.c_str(), tv) == 0) {
+            return;
+        }
+    }
+    ec = detail::make_system_error();
+    return;
 #elif defined(GHC_OS_MACOS)
 #ifdef __MAC_OS_X_VERSION_MIN_REQUIRED
 #if __MAC_OS_X_VERSION_MIN_REQUIRED < 101300
