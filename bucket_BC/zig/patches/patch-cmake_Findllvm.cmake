--- cmake/Findllvm.cmake.orig	2022-02-14 20:03:19 UTC
+++ cmake/Findllvm.cmake
@@ -71,6 +71,7 @@ elseif(ZIG_USE_LLVM_CONFIG)
   find_program(LLVM_CONFIG_EXE
       NAMES llvm-config-13 llvm-config-13.0 llvm-config130 llvm-config13 llvm-config
       PATHS
+          "/usr/local/llvm13/bin"
           "/mingw64/bin"
           "/c/msys64/mingw64/bin"
           "c:/msys64/mingw64/bin"
