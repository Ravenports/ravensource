--- cmake/modules/AddLLVM.cmake.orig	2023-10-17 06:20:52 UTC
+++ cmake/modules/AddLLVM.cmake
@@ -241,14 +241,10 @@ if (NOT DEFINED LLVM_LINKER_DETECTED AND
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
@@ -2354,7 +2350,7 @@ function(llvm_setup_rpath name)
   elseif(UNIX)
     set(_build_rpath "\$ORIGIN/../lib${LLVM_LIBDIR_SUFFIX}" ${extra_libdir})
     set(_install_rpath "\$ORIGIN/../lib${LLVM_LIBDIR_SUFFIX}")
-    if(${CMAKE_SYSTEM_NAME} MATCHES "(FreeBSD|DragonFly)")
+    if(${CMAKE_SYSTEM_NAME} MATCHES "(FreeBSD|DragonFly|MidnightBSD)")
       set_property(TARGET ${name} APPEND_STRING PROPERTY
                    LINK_FLAGS " -Wl,-z,origin ")
     endif()
