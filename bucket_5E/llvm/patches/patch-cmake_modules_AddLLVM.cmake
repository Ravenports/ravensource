--- cmake/modules/AddLLVM.cmake.orig	2026-10-19 23:57:12 UTC
+++ cmake/modules/AddLLVM.cmake
@@ -323,14 +323,10 @@ if (NOT DEFINED LLVM_LINKER_DETECTED AND
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
 
@@ -2709,7 +2705,7 @@ function(llvm_setup_rpath name)
       list(APPEND _build_rpath "\$ORIGIN/../lib${LLVM_LIBDIR_SUFFIX}/${LLVM_DEFAULT_TARGET_TRIPLE}")
       list(APPEND _install_rpath "\$ORIGIN/../lib${LLVM_LIBDIR_SUFFIX}/${LLVM_DEFAULT_TARGET_TRIPLE}")
     endif()
-    if("${CMAKE_SYSTEM_NAME}" MATCHES "(FreeBSD|DragonFly)")
+    if("${CMAKE_SYSTEM_NAME}" MATCHES "(FreeBSD|DragonFly|MidnightBSD)")
       set_property(TARGET ${name} APPEND_STRING PROPERTY
                    LINK_FLAGS " -Wl,-z,origin ")
     endif()
