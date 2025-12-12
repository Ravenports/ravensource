--- find-modules/FindInotify.cmake.orig	2025-12-05 13:18:18 UTC
+++ find-modules/FindInotify.cmake
@@ -56,9 +56,8 @@ if(Inotify_INCLUDE_DIRS)
         cmake_path(GET Inotify_INCLUDE_DIRS PARENT_PATH includes_prefix)
         cmake_path(GET Inotify_LIBRARIES PARENT_PATH lib_prefix)
         cmake_path(GET lib_prefix PARENT_PATH lib_prefix)
-        cmake_path(COMPARE includes_prefix EQUAL lib_prefix prefixes_match)
 
-        if(NOT prefixes_match)
+        if(NOT "${includes_prefix}" STREQUAL "${lib_prefix}")
             set(Inotify_FOUND TRUE)
             set(Inotify_LIBRARIES "" CACHE STRING "" FORCE)
             set(Inotify_INCLUDE_DIRS "" CACHE STRING "" FORCE)
