--- Source/JavaScriptCore/assembler/ARM64Assembler.h.orig	2025-08-11 07:56:47 UTC
+++ Source/JavaScriptCore/assembler/ARM64Assembler.h
@@ -3760,6 +3760,8 @@ public:
         sys_icache_invalidate(code, size);
 #elif OS(FUCHSIA)
         zx_cache_flush(code, size, ZX_CACHE_FLUSH_INSN);
+#elif OS(FREEBSD) || OS(NETBSD)
+        __clear_cache(code, reinterpret_cast<char*>(code) + size);
 #elif OS(LINUX)
         size_t page = pageSize();
         uintptr_t current = reinterpret_cast<uintptr_t>(code);
