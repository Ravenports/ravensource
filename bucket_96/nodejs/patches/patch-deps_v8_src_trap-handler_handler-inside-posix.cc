--- deps/v8/src/trap-handler/handler-inside-posix.cc.orig	2021-05-04 08:21:11 UTC
+++ deps/v8/src/trap-handler/handler-inside-posix.cc
@@ -27,7 +27,7 @@
 
 #include <signal.h>
 
-#if defined(V8_OS_LINUX) || defined(V8_OS_FREEBSD)
+#if V8_OS_LINUX || V8_OS_FREEBSD || V8_OS_DRAGONFLYBSD
 #include <ucontext.h>
 #elif V8_OS_MACOSX
 #include <sys/ucontext.h>
@@ -114,6 +114,8 @@ bool TryHandleSignal(int signum, siginfo
     auto* context_ip = &uc->uc_mcontext->__ss.__rip;
 #elif V8_OS_FREEBSD && V8_TARGET_ARCH_X64
     auto* context_ip = &uc->uc_mcontext.mc_rip;
+#elif V8_OS_DRAGONFLYBSD && V8_TARGET_ARCH_X64
+    auto* context_ip = &uc->uc_mcontext.mc_rip;
 #else
 #error Unsupported platform
 #endif
