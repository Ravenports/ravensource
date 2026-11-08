--- CMakeLists_Dependencies.cmake.orig	2026-10-27 19:38:30 UTC
+++ CMakeLists_Dependencies.cmake
@@ -66,7 +66,7 @@ endif()
 #>> OpenSceneGraph for 3D PDF Annocations
 
 #<< Qt
-set(CMAKE_PREFIX_PATH "${QT_PREFIX}/lib/cmake")
+set(CMAKE_PREFIX_PATH "${QT_PREFIX}/cmake")
 set(CMAKE_INCLUDE_CURRENT_DIR ON)
 
 set(QT_MIN_VERSION "6.5.0")
