--- cmake/modules/AddLLVM.cmake.orig	2017-05-19 01:55:05 UTC
+++ cmake/modules/AddLLVM.cmake
@@ -182,9 +182,6 @@ function(add_link_opts target_name)
         # ld64's implementation of -dead_strip breaks tools that use plugins.
         set_property(TARGET ${target_name} APPEND_STRING PROPERTY
                      LINK_FLAGS " -Wl,-dead_strip")
-      elseif(${CMAKE_SYSTEM_NAME} MATCHES "SunOS")
-        set_property(TARGET ${target_name} APPEND_STRING PROPERTY
-                     LINK_FLAGS " -Wl,-z -Wl,discard-unused=sections")
       elseif(NOT WIN32 AND NOT LLVM_LINKER_IS_GOLD)
         # Object files are compiled with -ffunction-data-sections.
         # Versions of bfd ld < 2.23.1 have a bug in --gc-sections that breaks
