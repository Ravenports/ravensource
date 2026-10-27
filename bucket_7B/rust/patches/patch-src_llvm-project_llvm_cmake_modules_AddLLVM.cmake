--- src/llvm-project/llvm/cmake/modules/AddLLVM.cmake.orig	2026-10-13 01:48:49 UTC
+++ src/llvm-project/llvm/cmake/modules/AddLLVM.cmake
@@ -2709,7 +2709,7 @@ function(llvm_setup_rpath name)
       list(APPEND _build_rpath "\$ORIGIN/../lib${LLVM_LIBDIR_SUFFIX}/${LLVM_DEFAULT_TARGET_TRIPLE}")
       list(APPEND _install_rpath "\$ORIGIN/../lib${LLVM_LIBDIR_SUFFIX}/${LLVM_DEFAULT_TARGET_TRIPLE}")
     endif()
-    if("${CMAKE_SYSTEM_NAME}" MATCHES "(FreeBSD|DragonFly)")
+    if("${CMAKE_SYSTEM_NAME}" MATCHES "(FreeBSD|DragonFly|MidnightBSD)")
       set_property(TARGET ${name} APPEND_STRING PROPERTY
                    LINK_FLAGS " -Wl,-z,origin ")
     endif()
