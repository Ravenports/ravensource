--- src/lib/utils/os_utils/os_utils.cpp.orig	2026-03-15 20:31:09 UTC
+++ src/lib/utils/os_utils/os_utils.cpp
@@ -552,7 +552,7 @@ std::vector<void*> OS::allocate_locked_p
       mmap_flags |= MAP_NOCORE;
       #endif
 
-      const int mmap_prot = PROT_READ | PROT_WRITE;
+      int mmap_prot = PROT_READ | PROT_WRITE;
 
       #if defined(PROT_MAX)
       mmap_prot |= PROT_MAX(mmap_prot);
