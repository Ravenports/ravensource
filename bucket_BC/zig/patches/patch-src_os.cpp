--- src/os.cpp.orig	2019-04-08 19:41:41 UTC
+++ src/os.cpp
@@ -51,7 +51,7 @@ typedef SSIZE_T ssize_t;
 
 #endif
 
-#if defined(ZIG_OS_LINUX) || defined(ZIG_OS_FREEBSD) || defined(ZIG_OS_NETBSD)
+#if defined(ZIG_OS_LINUX) || defined(ZIG_OS_FREEBSD) || defined(ZIG_OS_NETBSD) || defined(ZIG_OS_DRAGONFLY)
 #include <link.h>
 #endif
 
@@ -59,7 +59,7 @@ typedef SSIZE_T ssize_t;
 #include <sys/auxv.h>
 #endif
 
-#if defined(ZIG_OS_FREEBSD) || defined(ZIG_OS_NETBSD)
+#if defined(ZIG_OS_FREEBSD) || defined(ZIG_OS_NETBSD) || defined(ZIG_OS_DRAGONFLY)
 #include <sys/sysctl.h>
 #endif
 
@@ -84,7 +84,7 @@ static clock_serv_t macos_monotonic_cloc
 #if defined(__APPLE__) && !defined(environ)
 #include <crt_externs.h>
 #define environ (*_NSGetEnviron())
-#elif defined(ZIG_OS_FREEBSD) || defined(ZIG_OS_NETBSD)
+#elif defined(ZIG_OS_FREEBSD) || defined(ZIG_OS_NETBSD) || defined(ZIG_OS_DRAGONFLY)
 extern char **environ;
 #endif
 
@@ -1365,7 +1365,7 @@ static void init_rand() {
         zig_panic("unable to open /dev/urandom");
     }
     char bytes[sizeof(unsigned)];
-    size_t amt_read;
+    ssize_t amt_read;
     while ((amt_read = read(fd, bytes, sizeof(unsigned))) == -1) {
         if (errno == EINTR) continue;
         zig_panic("unable to read /dev/urandom");
@@ -1443,7 +1443,7 @@ Error os_self_exe_path(Buf *out_path) {
     }
     buf_resize(out_path, amt);
     return ErrorNone;
-#elif defined(ZIG_OS_FREEBSD)
+#elif defined(ZIG_OS_FREEBSD) || defined(ZIG_OS_DRAGONFLY)
     buf_resize(out_path, PATH_MAX);
     int mib[4] = { CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1 };
     size_t cb = PATH_MAX;
@@ -1779,7 +1779,7 @@ Error os_get_app_data_dir(Buf *out_path,
 }
 
 
-#if defined(ZIG_OS_LINUX) || defined(ZIG_OS_FREEBSD) || defined(ZIG_OS_NETBSD)
+#if defined(ZIG_OS_LINUX) || defined(ZIG_OS_FREEBSD) || defined(ZIG_OS_NETBSD) || defined(ZIG_OS_DRAGONFLY)
 static int self_exe_shared_libs_callback(struct dl_phdr_info *info, size_t size, void *data) {
     ZigList<Buf *> *libs = reinterpret_cast< ZigList<Buf *> *>(data);
     if (info->dlpi_name[0] == '/') {
@@ -1790,7 +1790,7 @@ static int self_exe_shared_libs_callback
 #endif
 
 Error os_self_exe_shared_libs(ZigList<Buf *> &paths) {
-#if defined(ZIG_OS_LINUX) || defined(ZIG_OS_FREEBSD) || defined(ZIG_OS_NETBSD)
+#if defined(ZIG_OS_LINUX) || defined(ZIG_OS_FREEBSD) || defined(ZIG_OS_NETBSD) || defined(ZIG_OS_DRAGONFLY)
     paths.resize(0);
     dl_iterate_phdr(self_exe_shared_libs_callback, &paths);
     return ErrorNone;
