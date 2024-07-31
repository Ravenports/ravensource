--- src/llvm-project/llvm/cmake/modules/AddLLVM.cmake.orig	2006-07-24 01:21:28 UTC
+++ src/llvm-project/llvm/cmake/modules/AddLLVM.cmake
@@ -2385,7 +2385,7 @@ function(llvm_setup_rpath name)
   elseif(UNIX)
     set(_build_rpath "\$ORIGIN/../lib${LLVM_LIBDIR_SUFFIX}" ${extra_libdir})
     set(_install_rpath "\$ORIGIN/../lib${LLVM_LIBDIR_SUFFIX}")
-    if(${CMAKE_SYSTEM_NAME} MATCHES "(FreeBSD|DragonFly)")
+    if(${CMAKE_SYSTEM_NAME} MATCHES "(FreeBSD|DragonFly|MidnightBSD)")
       set_property(TARGET ${name} APPEND_STRING PROPERTY
                    LINK_FLAGS " -Wl,-z,origin ")
     endif()
