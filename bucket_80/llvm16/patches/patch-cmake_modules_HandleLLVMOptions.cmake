--- cmake/modules/HandleLLVMOptions.cmake.orig	2023-06-10 22:58:16 UTC
+++ cmake/modules/HandleLLVMOptions.cmake
@@ -226,7 +226,7 @@ endif()
 
 # Pass -Wl,-z,defs. This makes sure all symbols are defined. Otherwise a DSO
 # build might work on ELF but fail on MachO/COFF.
-if(NOT (CMAKE_SYSTEM_NAME MATCHES "Darwin|FreeBSD|OpenBSD|DragonFly|AIX|OS390" OR
+if(NOT (TRUE OR
         WIN32 OR CYGWIN) AND
    NOT LLVM_USE_SANITIZER)
   set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,-z,defs")
