--- /home/tse/Packages/zig-0.4.0.orig/src/os.cpp	2019-04-08 22:41:41.000000000 +0300
+++ src/os.cpp	2019-04-26 14:02:24.568101000 +0300
@@ -51,7 +51,7 @@
 
 #endif
 
-#if defined(ZIG_OS_LINUX) || defined(ZIG_OS_FREEBSD) || defined(ZIG_OS_NETBSD)
+#if defined(ZIG_OS_LINUX) || defined(ZIG_OS_FREEBSD) || defined(ZIG_OS_NETBSD) || defined(ZIG_OS_DRAGONFLY)
 #include <link.h>
 #endif
 
@@ -59,7 +59,7 @@
 #include <sys/auxv.h>
 #endif
 
-#if defined(ZIG_OS_FREEBSD) || defined(ZIG_OS_NETBSD)
+#if defined(ZIG_OS_FREEBSD) || defined(ZIG_OS_NETBSD) || defined(ZIG_OS_DRAGONFLY)
 #include <sys/sysctl.h>
 #endif
 
@@ -84,7 +84,7 @@
 #if defined(__APPLE__) && !defined(environ)
 #include <crt_externs.h>
 #define environ (*_NSGetEnviron())
-#elif defined(ZIG_OS_FREEBSD) || defined(ZIG_OS_NETBSD)
+#elif defined(ZIG_OS_FREEBSD) || defined(ZIG_OS_NETBSD) || defined(ZIG_OS_DRAGONFLY)
 extern char **environ;
 #endif
 
@@ -1365,7 +1365,7 @@
         zig_panic("unable to open /dev/urandom");
     }
     char bytes[sizeof(unsigned)];
-    size_t amt_read;
+    ssize_t amt_read;
     while ((amt_read = read(fd, bytes, sizeof(unsigned))) == -1) {
         if (errno == EINTR) continue;
         zig_panic("unable to read /dev/urandom");
@@ -1443,7 +1443,7 @@
     }
     buf_resize(out_path, amt);
     return ErrorNone;
-#elif defined(ZIG_OS_FREEBSD)
+#elif defined(ZIG_OS_FREEBSD) || defined(ZIG_OS_DRAGONFLY)
     buf_resize(out_path, PATH_MAX);
     int mib[4] = { CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1 };
     size_t cb = PATH_MAX;
@@ -1779,7 +1779,7 @@
 }
 
 
-#if defined(ZIG_OS_LINUX) || defined(ZIG_OS_FREEBSD) || defined(ZIG_OS_NETBSD)
+#if defined(ZIG_OS_LINUX) || defined(ZIG_OS_FREEBSD) || defined(ZIG_OS_NETBSD) || defined(ZIG_OS_DRAGONFLY)
 static int self_exe_shared_libs_callback(struct dl_phdr_info *info, size_t size, void *data) {
     ZigList<Buf *> *libs = reinterpret_cast< ZigList<Buf *> *>(data);
     if (info->dlpi_name[0] == '/') {
@@ -1790,7 +1790,7 @@
 #endif
 
 Error os_self_exe_shared_libs(ZigList<Buf *> &paths) {
-#if defined(ZIG_OS_LINUX) || defined(ZIG_OS_FREEBSD) || defined(ZIG_OS_NETBSD)
+#if defined(ZIG_OS_LINUX) || defined(ZIG_OS_FREEBSD) || defined(ZIG_OS_NETBSD) || defined(ZIG_OS_DRAGONFLY)
     paths.resize(0);
     dl_iterate_phdr(self_exe_shared_libs_callback, &paths);
     return ErrorNone;
