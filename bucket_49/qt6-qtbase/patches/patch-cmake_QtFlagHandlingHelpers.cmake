--- cmake/QtFlagHandlingHelpers.cmake.orig	2021-01-26 18:29:22 UTC
+++ cmake/QtFlagHandlingHelpers.cmake
@@ -73,7 +73,6 @@ function(qt_internal_add_link_flags_no_u
         if (NOT HAVE_DASH_UNDEFINED_SYMBOLS AND NOT HAVE_DASH_DASH_NO_UNDEFINED)
             message(FATAL_ERROR "Platform linker doesn't support erroring upon encountering undefined symbols. Target:\"${target}\".")
         endif()
-        target_link_options("${target}" PRIVATE "${no_undefined_flag}")
     endif()
 endfunction()
 
