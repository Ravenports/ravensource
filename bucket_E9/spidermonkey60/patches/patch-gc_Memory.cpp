--- gc/Memory.cpp.orig	2019-09-01 13:09:17 UTC
+++ gc/Memory.cpp
@@ -18,9 +18,12 @@
 #include "util/Windows.h"
 #include <psapi.h>
 
-#elif defined(SOLARIS)
+#elif defined(__sun__)
 
 #include <sys/mman.h>
+#include <sys/stat.h>
+#include <sys/types.h>
+#include <sys/resource.h>
 #include <unistd.h>
 
 #elif defined(XP_UNIX)
@@ -419,6 +422,7 @@ static inline void* MapMemoryAt(void* de
                                 off_t offset = 0) {
 
 #if defined(__ia64__) || defined(__aarch64__) ||  \
+    (defined(__sun__) && defined(__x86_64__)) ||  \
     (defined(__sparc__) && defined(__arch64__) && \
      (defined(__NetBSD__) || defined(__linux__)))
   MOZ_ASSERT((0xffff800000000000ULL & (uintptr_t(desired) + length - 1)) == 0);
@@ -468,6 +472,7 @@ static inline void* MapMemory(size_t len
   }
   return region;
 #elif defined(__aarch64__) || \
+    (defined(__sun__) && defined(__x86_64__)) || \
     (defined(__sparc__) && defined(__arch64__) && defined(__linux__))
   /*
    * There might be similar virtual address issue on arm64 which depends on
@@ -655,8 +660,9 @@ bool MarkPagesUnused(void* p, size_t siz
   if (!DecommitEnabled()) return false;
 
   MOZ_ASSERT(OffsetFromAligned(p, pageSize) == 0);
-#if defined(XP_SOLARIS)
-  int result = posix_madvise(p, size, POSIX_MADV_DONTNEED);
+#ifdef __sun__
+  //int result = madvise(reinterpret_cast<caddr_t>(p), size, MADV_DONTNEED);
+  int result = 0;
 #else
   int result = madvise(p, size, MADV_DONTNEED);
 #endif
