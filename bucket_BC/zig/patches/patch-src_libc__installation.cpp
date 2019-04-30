--- src/libc_installation.cpp.orig	2019-04-08 19:41:41 UTC
+++ src/libc_installation.cpp
@@ -459,7 +459,7 @@ Error zig_libc_find_native(ZigLibCInstal
 #else
     if ((err = zig_libc_find_native_include_dir_posix(self, verbose)))
         return err;
-#if defined(ZIG_OS_FREEBSD) || defined(ZIG_OS_NETBSD)
+#if defined(ZIG_OS_FREEBSD) || defined(ZIG_OS_NETBSD) || defined(ZIG_OS_DRAGONFLY)
     buf_init_from_str(&self->crt_dir, "/usr/lib");
 #elif defined(ZIG_OS_LINUX)
     if ((err = zig_libc_find_native_crt_dir_posix(self, verbose)))
