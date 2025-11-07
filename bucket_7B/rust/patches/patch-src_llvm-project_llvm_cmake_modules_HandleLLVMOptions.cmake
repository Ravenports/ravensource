--- src/llvm-project/llvm/cmake/modules/HandleLLVMOptions.cmake.orig	2025-09-14 15:05:11 UTC
+++ src/llvm-project/llvm/cmake/modules/HandleLLVMOptions.cmake
@@ -312,7 +312,7 @@ endif()
 
 # Pass -Wl,-z,defs. This makes sure all symbols are defined. Otherwise a DSO
 # build might work on ELF but fail on MachO/COFF.
-if(NOT (CMAKE_SYSTEM_NAME MATCHES "Darwin|FreeBSD|OpenBSD|DragonFly|AIX|OS390|Emscripten" OR
+if(NOT (CMAKE_SYSTEM_NAME MATCHES "Darwin|FreeBSD|OpenBSD|DragonFly|MidnightBSD|AIX|OS390|Emscripten" OR
         WIN32 OR CYGWIN) AND
    NOT LLVM_USE_SANITIZER)
   set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,-z,defs")
