--- ../zig-0.4.0.orig/src/libc_installation.cpp	2019-04-08 22:41:41.000000000 +0300
+++ src/libc_installation.cpp	2019-04-26 14:14:34.411752000 +0300
@@ -459,7 +459,7 @@
 #else
     if ((err = zig_libc_find_native_include_dir_posix(self, verbose)))
         return err;
-#if defined(ZIG_OS_FREEBSD) || defined(ZIG_OS_NETBSD)
+#if defined(ZIG_OS_FREEBSD) || defined(ZIG_OS_NETBSD) || defined(ZIG_OS_DRAGONFLY)
     buf_init_from_str(&self->crt_dir, "/usr/lib");
 #elif defined(ZIG_OS_LINUX)
     if ((err = zig_libc_find_native_crt_dir_posix(self, verbose)))
