--- cmake/exports.cmake.orig	2026-05-13 23:13:38 UTC
+++ cmake/exports.cmake
@@ -68,7 +68,7 @@ function(setup_exports_target)
                    APPEND_STRING
                    PROPERTY LINK_FLAGS "${aom_sym_file}")
     endif()
-  else()
+  elseif(NOT CMAKE_SYSTEM_NAME STREQUAL "SunOS")
     set_property(TARGET aom
                  APPEND_STRING
                  PROPERTY LINK_FLAGS "-Wl,--version-script,${aom_sym_file}")
