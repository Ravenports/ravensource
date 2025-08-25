--- deps/v8/src/trap-handler/handler-inside-posix.cc.orig	2025-08-14 20:34:24 UTC
+++ deps/v8/src/trap-handler/handler-inside-posix.cc
@@ -27,7 +27,7 @@
 
 #include <signal.h>
 
-#if defined(V8_OS_LINUX) || defined(V8_OS_FREEBSD)
+#if V8_OS_LINUX || V8_OS_FREEBSD || V8_OS_DRAGONFLYBSD
 #include <ucontext.h>
 #elif V8_OS_DARWIN
 #include <sys/ucontext.h>
@@ -61,6 +61,8 @@ namespace trap_handler {
 #define CONTEXT_REG(reg, REG) &uc->uc_mcontext->__ss.__##reg
 #elif V8_OS_FREEBSD
 #define CONTEXT_REG(reg, REG) &uc->uc_mcontext.mc_##reg
+#elif V8_OS_DRAGONFLYBSD
+#define CONTEXT_REG(reg, REG) &uc->uc_mcontext.mc_##reg
 #else
 #error "Unsupported platform."
 #endif
