--- cmake/Macros.cmake.orig	2025-04-22 13:06:02 UTC
+++ cmake/Macros.cmake
@@ -244,7 +244,7 @@ macro(sfml_add_library module)
             "${CMAKE_CURRENT_BINARY_DIR}/tools/pkg-config/${target}.pc"
             @ONLY)
         install(FILES "${CMAKE_CURRENT_BINARY_DIR}/tools/pkg-config/${target}.pc"
-            DESTINATION "${SFML_PKGCONFIG_INSTALL_DIR}")
+            DESTINATION "lib/pkgconfig")
     endif()
 
     # because the frameworks directory hierarchy has to be set up before any target files
