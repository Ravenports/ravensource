--- cmake/QtFlagHandlingHelpers.cmake.orig	2025-11-12 10:17:57 UTC
+++ cmake/QtFlagHandlingHelpers.cmake
@@ -187,7 +187,6 @@ function(qt_internal_add_link_flags_no_u
                 "Target:\"${target}\". "
                 "Test errors: \n ${test_output_undefined_error} \n ${test_output_no_undefined}")
         endif()
-        target_link_options("${target}" PRIVATE "${no_undefined_flag}")
     endif()
 endfunction()
 
