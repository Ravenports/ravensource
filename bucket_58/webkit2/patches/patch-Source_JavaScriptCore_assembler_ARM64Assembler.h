--- Source/JavaScriptCore/assembler/ARM64Assembler.h.orig	2018-10-27 21:20:55 UTC
+++ Source/JavaScriptCore/assembler/ARM64Assembler.h
@@ -2865,6 +2865,8 @@ public:
         sys_cache_control(kCacheFunctionPrepareForExecution, code, size);
 #elif OS(FUCHSIA)
         zx_cache_flush(code, size, ZX_CACHE_FLUSH_INSN);
+#elif OS(FREEBSD) || OS(NETBSD)
+        __clear_cache(code, reinterpret_cast<char*>(code) + size);
 #elif OS(LINUX)
         size_t page = pageSize();
         uintptr_t current = reinterpret_cast<uintptr_t>(code);
