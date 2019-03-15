--- src/llvm/cmake/modules/HandleLLVMOptions.cmake.orig	2018-12-18 09:55:21 UTC
+++ src/llvm/cmake/modules/HandleLLVMOptions.cmake
@@ -138,6 +138,7 @@ endif()
 # build might work on ELF but fail on MachO/COFF.
 if(NOT (${CMAKE_SYSTEM_NAME} MATCHES "Darwin" OR WIN32 OR CYGWIN OR
         ${CMAKE_SYSTEM_NAME} MATCHES "FreeBSD" OR
+        ${CMAKE_SYSTEM_NAME} MATCHES "DragonFly" OR
         ${CMAKE_SYSTEM_NAME} MATCHES "OpenBSD") AND
    NOT LLVM_USE_SANITIZER)
   set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,-z,defs")
