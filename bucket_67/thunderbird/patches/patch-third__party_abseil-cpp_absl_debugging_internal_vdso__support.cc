--- third_party/abseil-cpp/absl/debugging/internal/vdso_support.cc.orig	2026-11-07 02:40:20 UTC
+++ third_party/abseil-cpp/absl/debugging/internal/vdso_support.cc
@@ -28,11 +28,15 @@
 
 #include <errno.h>
 #include <fcntl.h>
+#   if defined(__linux__) || defined(__DragonFly__) || defined(__NetBSD__)
+#if __has_include(<sys/syscall.h>)
+#include <sys/syscall.h>
+#endif
+#   else
 #if __has_include(<syscall.h>)
 #include <syscall.h>
-#elif __has_include(<sys/syscall.h>)
-#include <sys/syscall.h>
 #endif
+#   endif
 #include <unistd.h>
 
 #if !defined(__UCLIBC__) && defined(__GLIBC__) && \
@@ -56,7 +60,7 @@
 using Elf32_auxv_t = Aux32Info;
 using Elf64_auxv_t = Aux64Info;
 #endif
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__DragonFly__)
 #if defined(__ELF_WORD_SIZE) && __ELF_WORD_SIZE == 64
 using Elf64_auxv_t = Elf64_Auxinfo;
 #endif
