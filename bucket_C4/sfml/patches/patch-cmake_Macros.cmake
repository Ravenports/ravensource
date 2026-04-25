--- cmake/Macros.cmake.orig	2026-04-16 13:24:07 UTC
+++ cmake/Macros.cmake
@@ -247,7 +247,7 @@ macro(sfml_add_library module)
             "${CMAKE_CURRENT_BINARY_DIR}/tools/pkg-config/${target}.pc"
             @ONLY)
         install(FILES "${CMAKE_CURRENT_BINARY_DIR}/tools/pkg-config/${target}.pc"
-            DESTINATION "${SFML_PKGCONFIG_INSTALL_DIR}")
+            DESTINATION "lib/pkgconfig")
     endif()
 
     # because the frameworks directory hierarchy has to be set up before any target files
