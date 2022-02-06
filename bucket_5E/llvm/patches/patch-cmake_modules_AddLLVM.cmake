--- cmake/modules/AddLLVM.cmake.orig	2022-01-20 21:31:59 UTC
+++ cmake/modules/AddLLVM.cmake
@@ -205,14 +205,10 @@ if (NOT DEFINED LLVM_LINKER_DETECTED)
       set(LLVM_LINKER_DETECTED YES CACHE INTERNAL "")
       set(LLVM_LINKER_IS_GNULD YES CACHE INTERNAL "")
       message(STATUS "Linker detection: GNU ld")
-    elseif("${stderr}" MATCHES "Solaris Link Editors" OR
-           "${stdout}" MATCHES "Solaris Link Editors")
+    else()
       set(LLVM_LINKER_DETECTED YES CACHE INTERNAL "")
       set(LLVM_LINKER_IS_SOLARISLD YES CACHE INTERNAL "")
       message(STATUS "Linker detection: Solaris ld")
-    else()
-      set(LLVM_LINKER_DETECTED NO CACHE INTERNAL "")
-      message(STATUS "Linker detection: unknown")
     endif()
   endif()
 endif()
