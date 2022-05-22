Add support for NetBSD.

--- Source/WTF/wtf/PlatformHave.h.orig	2022-02-23 11:41:47 UTC
+++ Source/WTF/wtf/PlatformHave.h
@@ -229,7 +229,7 @@
 #define HAVE_HOSTED_CORE_ANIMATION 1
 #endif
 
-#if OS(DARWIN) || OS(FUCHSIA) || ((OS(FREEBSD) || OS(OPENBSD) || OS(LINUX)) && (CPU(X86) || CPU(X86_64) || CPU(ARM) || CPU(ARM64) || CPU(MIPS) || CPU(RISCV64)))
+#if OS(DARWIN) || OS(FUCHSIA) || ((OS(FREEBSD) || OS(OPENBSD) || OS(NETBSD) || OS(LINUX)) && (CPU(X86) || CPU(X86_64) || CPU(ARM) || CPU(ARM64) || CPU(MIPS) || CPU(RISCV64)))
 #define HAVE_MACHINE_CONTEXT 1
 #endif
 
