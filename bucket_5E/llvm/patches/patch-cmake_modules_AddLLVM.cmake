--- cmake/modules/AddLLVM.cmake.orig	2025-04-29 23:05:17 UTC
+++ cmake/modules/AddLLVM.cmake
@@ -263,14 +263,10 @@ if (NOT DEFINED LLVM_LINKER_DETECTED AND
       set(LLVM_LINKER_IS_SOLARISLD YES CACHE INTERNAL "")
       set(LLVM_LINKER_IS_SOLARISLD_ILLUMOS YES CACHE INTERNAL "")
       message(STATUS "Linker detection: Solaris ld (illumos)")
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
 
@@ -2526,7 +2522,7 @@ function(llvm_setup_rpath name)
   elseif(UNIX)
     set(_build_rpath "\$ORIGIN/../lib${LLVM_LIBDIR_SUFFIX}" ${extra_libdir})
     set(_install_rpath "\$ORIGIN/../lib${LLVM_LIBDIR_SUFFIX}")
-    if(${CMAKE_SYSTEM_NAME} MATCHES "(FreeBSD|DragonFly)")
+    if(${CMAKE_SYSTEM_NAME} MATCHES "(FreeBSD|DragonFly|MidnightBSD)")
       set_property(TARGET ${name} APPEND_STRING PROPERTY
                    LINK_FLAGS " -Wl,-z,origin ")
     endif()
