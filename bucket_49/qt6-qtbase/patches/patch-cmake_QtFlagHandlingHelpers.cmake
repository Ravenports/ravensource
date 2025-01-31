--- cmake/QtFlagHandlingHelpers.cmake.orig	2024-11-14 11:02:40 UTC
+++ cmake/QtFlagHandlingHelpers.cmake
@@ -182,7 +182,6 @@ function(qt_internal_add_link_flags_no_u
         if (NOT HAVE_DASH_UNDEFINED_SYMBOLS AND NOT HAVE_DASH_DASH_NO_UNDEFINED)
             message(FATAL_ERROR "Platform linker doesn't support erroring upon encountering undefined symbols. Target:\"${target}\".")
         endif()
-        target_link_options("${target}" PRIVATE "${no_undefined_flag}")
     endif()
 endfunction()
 
