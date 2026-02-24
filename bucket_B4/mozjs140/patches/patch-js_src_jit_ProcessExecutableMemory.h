--- ../../js/src/jit/ProcessExecutableMemory.h.orig	2026-02-13 16:59:08 UTC
+++ ../../js/src/jit/ProcessExecutableMemory.h
@@ -14,7 +14,7 @@ namespace jit {
 
 // Limit on the number of bytes of executable memory to prevent JIT spraying
 // attacks.
-#if JS_BITS_PER_WORD == 32
+#if JS_BITS_PER_WORD == 32 || defined(__NetBSD__)
 static const size_t MaxCodeBytesPerProcess = 140 * 1024 * 1024;
 #else
 // This is the largest number which satisfies various alignment static
