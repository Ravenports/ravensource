--- cmake/FindFFmpeg.cmake.orig	2026-05-08 03:28:44 UTC
+++ cmake/FindFFmpeg.cmake
@@ -345,7 +345,7 @@ foreach (_component ${FFmpeg_FIND_COMPON
             target_link_directories(${_target} INTERFACE ${${_component}_LIBRARY_DIR})
 
             __ffmpeg_internal_set_dependencies(${_component})
-            if (UNIX AND NOT APPLE)
+            if (UNIX AND NOT APPLE AND NOT CMAKE_SYSTEM_NAME MATCHES "SunOS")
                 target_link_options(${_target} INTERFACE  "-Wl,--exclude-libs=lib${_lowerComponent}")
             endif ()
         endif()
