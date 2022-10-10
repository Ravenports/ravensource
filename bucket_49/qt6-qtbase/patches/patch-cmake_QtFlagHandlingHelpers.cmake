--- cmake/QtFlagHandlingHelpers.cmake.orig	2022-09-19 10:23:04 UTC
+++ cmake/QtFlagHandlingHelpers.cmake
@@ -82,7 +82,6 @@ function(qt_internal_add_link_flags_no_u
         if (NOT HAVE_DASH_UNDEFINED_SYMBOLS AND NOT HAVE_DASH_DASH_NO_UNDEFINED)
             message(FATAL_ERROR "Platform linker doesn't support erroring upon encountering undefined symbols. Target:\"${target}\".")
         endif()
-        target_link_options("${target}" PRIVATE "${no_undefined_flag}")
     endif()
 endfunction()
 
