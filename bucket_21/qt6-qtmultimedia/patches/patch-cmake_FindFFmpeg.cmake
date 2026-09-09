--- cmake/FindFFmpeg.cmake.orig	2026-07-03 07:13:40 UTC
+++ cmake/FindFFmpeg.cmake
@@ -344,7 +344,7 @@ foreach (_component ${FFmpeg_FIND_COMPON
             target_link_libraries(${_target} INTERFACE "${${_component}_LIBRARY}")
 
             __ffmpeg_internal_set_dependencies(${_component})
-            if (UNIX AND NOT APPLE)
+            if (UNIX AND NOT APPLE AND NOT CMAKE_SYSTEM_NAME MATCHES "SunOS")
                 target_link_options(${_target} INTERFACE  "-Wl,--exclude-libs=lib${_lowerComponent}")
             endif ()
         endif()
