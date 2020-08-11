--- deps/v8/src/libsampler/sampler.cc.orig	2020-08-11 14:32:04 UTC
+++ deps/v8/src/libsampler/sampler.cc
@@ -469,7 +469,7 @@ void SignalHandler::FillRegisterState(vo
   state->sp = reinterpret_cast<void*>(mcontext->__ss.__esp);
   state->fp = reinterpret_cast<void*>(mcontext->__ss.__ebp);
 #endif  // V8_HOST_ARCH_IA32
-#elif V8_OS_FREEBSD
+#elif V8_OS_FREEBSD || V8_OS_DRAGONFLYBSD
 #if V8_HOST_ARCH_IA32
   state->pc = reinterpret_cast<void*>(mcontext.mc_eip);
   state->sp = reinterpret_cast<void*>(mcontext.mc_esp);
