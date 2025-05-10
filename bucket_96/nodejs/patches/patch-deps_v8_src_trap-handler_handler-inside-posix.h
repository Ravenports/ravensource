--- deps/v8/src/trap-handler/handler-inside-posix.h.orig	2025-05-08 08:26:19 UTC
+++ deps/v8/src/trap-handler/handler-inside-posix.h
@@ -13,7 +13,7 @@ namespace v8 {
 namespace internal {
 namespace trap_handler {
 
-#if V8_OS_LINUX || V8_OS_FREEBSD
+#if defined(V8_OS_LINUX) || defined(V8_OS_FREEBSD) || defined(V8_OS_DRAGONFLYBSD)
 constexpr int kOobSignal = SIGSEGV;
 #elif V8_OS_DARWIN
 constexpr int kOobSignal = SIGBUS;
