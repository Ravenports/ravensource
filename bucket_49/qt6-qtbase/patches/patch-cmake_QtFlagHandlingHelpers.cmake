--- cmake/QtFlagHandlingHelpers.cmake.orig	2025-11-12 10:17:57 UTC
+++ cmake/QtFlagHandlingHelpers.cmake
@@ -187,7 +187,6 @@ function(qt_internal_add_link_flags_no_u
                 "Target:\"${target}\". "
                 "Test errors: \n ${test_output_undefined_error} \n ${test_output_no_undefined}")
         endif()
-        target_link_options("${target}" PRIVATE "${no_undefined_flag}")
     endif()
 endfunction()
 
@@ -218,8 +217,6 @@ function(qt_internal_apply_gc_binaries t
     if ((GCC OR CLANG) AND NOT WASM AND NOT UIKIT AND NOT MSVC)
         if(APPLE)
             set(gc_sections_flag "-Wl,-dead_strip")
-        elseif(SOLARIS)
-            set(gc_sections_flag "-Wl,-z,ignore")
         elseif(LINUX OR BSD OR WIN32 OR ANDROID)
             set(gc_sections_flag "-Wl,--gc-sections")
         endif()
