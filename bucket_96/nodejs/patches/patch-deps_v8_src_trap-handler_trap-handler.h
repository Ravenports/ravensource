--- deps/v8/src/trap-handler/trap-handler.h.orig	2025-05-08 08:26:19 UTC
+++ deps/v8/src/trap-handler/trap-handler.h
@@ -18,6 +18,7 @@ namespace v8::internal::trap_handler {
 // X64 on Linux, Windows, MacOS, FreeBSD.
 #if V8_HOST_ARCH_X64 && V8_TARGET_ARCH_X64 &&                        \
     ((V8_OS_LINUX && !V8_OS_ANDROID) || V8_OS_WIN || V8_OS_DARWIN || \
+     V8_OS_DRAGONFLYBSD || \
      V8_OS_FREEBSD)
 #define V8_TRAP_HANDLER_SUPPORTED true
 // Arm64 (non-simulator) on Linux, Windows, MacOS.
