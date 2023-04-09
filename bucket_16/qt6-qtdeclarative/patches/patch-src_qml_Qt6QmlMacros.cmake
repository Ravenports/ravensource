--- src/qml/Qt6QmlMacros.cmake.orig	2023-03-23 08:11:12 UTC
+++ src/qml/Qt6QmlMacros.cmake
@@ -1672,7 +1672,6 @@ function(qt6_add_qml_plugin target)
         string(REPLACE "/" ";" path "qml/${arg_TARGET_PATH}")
         list(LENGTH path path_count)
         string(REPEAT "../" ${path_count} rel_path)
-        string(APPEND rel_path "${CMAKE_INSTALL_LIBDIR}")
         if(APPLE)
             set(install_rpath
                 # If embedded in an app bundle, search in a bundle-local path
@@ -1688,7 +1687,7 @@ function(qt6_add_qml_plugin target)
                 "@loader_path/${rel_path}"
             )
         else()
-            set(install_rpath "$ORIGIN/${rel_path}")
+            set(install_rpath "${CMAKE_INSTALL_LIBDIR}:$ORIGIN/${rel_path}")
         endif()
         set_target_properties(${target} PROPERTIES INSTALL_RPATH "${install_rpath}")
     endif()
