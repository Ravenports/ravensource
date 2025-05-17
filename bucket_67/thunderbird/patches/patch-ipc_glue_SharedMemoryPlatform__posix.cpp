--- ipc/glue/SharedMemoryPlatform_posix.cpp.orig	2025-05-12 17:23:25 UTC
+++ ipc/glue/SharedMemoryPlatform_posix.cpp
@@ -449,7 +449,7 @@ bool Platform::Protect(char* aAddr, size
 }
 
 void* Platform::FindFreeAddressSpace(size_t aSize) {
-#ifndef __FreeBSD__
+#if !defined(__FreeBSD__) && !defined(__DragonFly__)
   constexpr int flags = MAP_ANONYMOUS | MAP_NORESERVE | MAP_PRIVATE;
 #else
   constexpr int flags = MAP_ANONYMOUS | MAP_PRIVATE;
