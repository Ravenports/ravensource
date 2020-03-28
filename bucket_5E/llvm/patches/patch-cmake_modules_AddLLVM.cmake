--- cmake/modules/AddLLVM.cmake.orig	2020-03-23 15:01:02 UTC
+++ cmake/modules/AddLLVM.cmake
@@ -198,13 +198,9 @@ elseif(NOT WIN32)
   elseif("${stdout}" MATCHES "GNU ld")
     set(LLVM_LINKER_IS_GNULD YES)
     message(STATUS "Linker detection: GNU ld")
-  elseif("${stderr}" MATCHES "Solaris Link Editors" OR
-         "${stdout}" MATCHES "Solaris Link Editors")
+  else()
     set(LLVM_LINKER_IS_SOLARISLD YES)
     message(STATUS "Linker detection: Solaris ld")
-  else()
-    set(LLVM_LINKER_DETECTED NO)
-    message(STATUS "Linker detection: unknown")
   endif()
 endif()
 
@@ -233,9 +229,6 @@ function(add_link_opts target_name)
         # ld64's implementation of -dead_strip breaks tools that use plugins.
         set_property(TARGET ${target_name} APPEND_STRING PROPERTY
                      LINK_FLAGS " -Wl,-dead_strip")
-      elseif(${CMAKE_SYSTEM_NAME} MATCHES "SunOS")
-        set_property(TARGET ${target_name} APPEND_STRING PROPERTY
-                     LINK_FLAGS " -Wl,-z -Wl,discard-unused=sections")
       elseif(NOT WIN32 AND NOT LLVM_LINKER_IS_GOLD AND
              NOT ${CMAKE_SYSTEM_NAME} MATCHES "OpenBSD|AIX")
         # Object files are compiled with -ffunction-data-sections.
