--- cmake/QtFlagHandlingHelpers.cmake.orig	2025-08-11 04:54:51 UTC
+++ cmake/QtFlagHandlingHelpers.cmake
@@ -187,7 +187,6 @@ function(qt_internal_add_link_flags_no_u
                 "Target:\"${target}\". "
                 "Test errors: \n ${test_output_undefined_error} \n ${test_output_no_undefined}")
         endif()
-        target_link_options("${target}" PRIVATE "${no_undefined_flag}")
     endif()
 endfunction()
 
