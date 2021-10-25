$NetBSD: patch-Source_WTF_wtf_PlatformHave.h,v 1.2 2021/05/13 08:20:58 leot Exp $

Add support for NetBSD.

--- Source/WTF/wtf/PlatformHave.h.orig	2021-09-01 09:16:49 UTC
+++ Source/WTF/wtf/PlatformHave.h
@@ -222,7 +222,7 @@
 #define HAVE_HOSTED_CORE_ANIMATION 1
 #endif
 
-#if OS(DARWIN) || OS(FUCHSIA) || ((OS(FREEBSD) || OS(LINUX)) && (CPU(X86) || CPU(X86_64) || CPU(ARM) || CPU(ARM64) || CPU(MIPS)))
+#if OS(DARWIN) || OS(FUCHSIA) || ((OS(FREEBSD) || OS(NETBSD) || OS(LINUX)) && (CPU(X86) || CPU(X86_64) || CPU(ARM) || CPU(ARM64) || CPU(MIPS)))
 #define HAVE_MACHINE_CONTEXT 1
 #endif
 
