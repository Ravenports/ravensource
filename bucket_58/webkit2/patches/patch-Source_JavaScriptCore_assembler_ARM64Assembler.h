--- Source/JavaScriptCore/assembler/ARM64Assembler.h.orig	2022-02-23 11:41:41 UTC
+++ Source/JavaScriptCore/assembler/ARM64Assembler.h
@@ -2947,6 +2947,8 @@ public:
         sys_cache_control(kCacheFunctionPrepareForExecution, code, size);
 #elif OS(FUCHSIA)
         zx_cache_flush(code, size, ZX_CACHE_FLUSH_INSN);
+#elif OS(FREEBSD) || OS(NETBSD)
+        __clear_cache(code, reinterpret_cast<char*>(code) + size);
 #elif OS(LINUX)
         size_t page = pageSize();
         uintptr_t current = reinterpret_cast<uintptr_t>(code);
