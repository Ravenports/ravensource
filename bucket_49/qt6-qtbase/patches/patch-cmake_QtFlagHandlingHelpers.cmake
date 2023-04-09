--- cmake/QtFlagHandlingHelpers.cmake.orig	2023-03-14 08:29:43 UTC
+++ cmake/QtFlagHandlingHelpers.cmake
@@ -110,7 +110,6 @@ function(qt_internal_add_link_flags_no_u
         if (NOT HAVE_DASH_UNDEFINED_SYMBOLS AND NOT HAVE_DASH_DASH_NO_UNDEFINED)
             message(FATAL_ERROR "Platform linker doesn't support erroring upon encountering undefined symbols. Target:\"${target}\".")
         endif()
-        target_link_options("${target}" PRIVATE "${no_undefined_flag}")
     endif()
 endfunction()
 
