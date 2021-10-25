$NetBSD: patch-Source_JavaScriptCore_runtime_MachineContext.h,v 1.2 2021/05/13 08:20:58 leot Exp $

Add support for NetBSD.

--- Source/JavaScriptCore/runtime/MachineContext.h.orig	2021-09-01 09:16:46 UTC
+++ Source/JavaScriptCore/runtime/MachineContext.h
@@ -195,6 +195,22 @@ static inline void*& stackPointerImpl(mc
 #error Unknown Architecture
 #endif
 
+#elif OS(NETBSD)
+
+#if CPU(X86)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.__gregs[_REG_UESP]);
+#elif CPU(X86_64)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.__gregs[_REG_RSP]);
+#elif CPU(ARM)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.__gregs[_REG_SP]);
+#elif CPU(ARM64)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.__gregs[_REG_SP]);
+#elif CPU(MIPS)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.__gregs[_REG_SP]);
+#else
+#error Unknown Architecture
+#endif
+
 #elif OS(FUCHSIA) || OS(LINUX)
 
 #if CPU(X86)
@@ -346,6 +362,22 @@ static inline void*& framePointerImpl(mc
 #error Unknown Architecture
 #endif
 
+#elif OS(NETBSD)
+
+#if CPU(X86)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.__gregs[_REG_EBP]);
+#elif CPU(X86_64)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.__gregs[_REG_RBP]);
+#elif CPU(ARM)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.__gregs[_REG_FP]);
+#elif CPU(ARM64)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.__gregs[_REG_FP]);
+#elif CPU(MIPS)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.__gregs[_REG_S8]);
+#else
+#error Unknown Architecture
+#endif
+
 #elif OS(FUCHSIA) || OS(LINUX)
 
 // The following sequence depends on glibc's sys/ucontext.h.
@@ -496,6 +528,22 @@ static inline void*& instructionPointerI
 #else
 #error Unknown Architecture
 #endif
+ 
+#elif OS(NETBSD)
+
+#if CPU(X86)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.__gregs[_REG_EIP]);
+#elif CPU(X86_64)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.__gregs[_REG_RIP]);
+#elif CPU(ARM)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.__gregs[_REG_PC]);
+#elif CPU(ARM64)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.__gregs[_REG_PC]);
+#elif CPU(MIPS)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.__gregs[_REG_EPC]);
+#else
+#error Unknown Architecture
+#endif
 
 #elif OS(FUCHSIA) || OS(LINUX)
 
@@ -654,6 +702,22 @@ inline void*& argumentPointer<1>(mcontex
 #else
 #error Unknown Architecture
 #endif
+ 
+#elif OS(NETBSD)
+
+#if CPU(X86)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.__gregs[_REG_EDX]);
+#elif CPU(X86_64)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.__gregs[_REG_RSI]);
+#elif CPU(ARM)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.__gregs[_REG_R1]);
+#elif CPU(ARM64)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.__gregs[_REG_X1]);
+#elif CPU(MIPS)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.__gregs[_REG_A1]);
+#else
+#error Unknown Architecture
+#endif
 
 #elif OS(FUCHSIA) || OS(LINUX)
 
@@ -771,6 +835,22 @@ inline void*& llintInstructionPointer(mc
 #else
 #error Unknown Architecture
 #endif
+ 
+#elif OS(NETBSD)
+
+#if CPU(X86)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.__gregs[_REG_ESI]);
+#elif CPU(X86_64)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.__gregs[_REG_R8]);
+#elif CPU(ARM)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.__gregs[_REG_R8]);
+#elif CPU(ARM64)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.__gregs[_REG_X4]);
+#elif CPU(MIPS)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.__gregs[_REG_T4]);
+#else
+#error Unknown Architecture
+#endif
 
 #elif OS(FUCHSIA) || OS(LINUX)
 
