--- deps/v8/src/base/cpu.cc.orig	2018-12-18 16:49:45 UTC
+++ deps/v8/src/base/cpu.cc
@@ -424,6 +424,7 @@ CPU::CPU()
 
 #if V8_OS_LINUX
 
+#if V8_OS_LINUX
   CPUInfo cpu_info;
 
   // Extract implementor from the "CPU implementer" field.
@@ -604,6 +605,8 @@ CPU::CPU()
 #elif V8_HOST_ARCH_ARM64
 // Implementer, variant and part are currently unused under ARM64.
 
+#endif  // V8_OS_LINUX
+
 #elif V8_HOST_ARCH_PPC
 
 #ifndef USE_SIMULATOR
