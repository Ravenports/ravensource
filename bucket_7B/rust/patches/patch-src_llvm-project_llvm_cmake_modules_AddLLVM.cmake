--- src/llvm-project/llvm/cmake/modules/AddLLVM.cmake.orig	2025-11-07 03:39:30 UTC
+++ src/llvm-project/llvm/cmake/modules/AddLLVM.cmake
@@ -2549,7 +2549,7 @@ function(llvm_setup_rpath name)
   elseif(UNIX)
     set(_build_rpath "\$ORIGIN/../lib${LLVM_LIBDIR_SUFFIX}" ${extra_libdir})
     set(_install_rpath "\$ORIGIN/../lib${LLVM_LIBDIR_SUFFIX}")
-    if(${CMAKE_SYSTEM_NAME} MATCHES "(FreeBSD|DragonFly)")
+    if(${CMAKE_SYSTEM_NAME} MATCHES "(FreeBSD|DragonFly|MidnightBSD)")
       set_property(TARGET ${name} APPEND_STRING PROPERTY
                    LINK_FLAGS " -Wl,-z,origin ")
     endif()
