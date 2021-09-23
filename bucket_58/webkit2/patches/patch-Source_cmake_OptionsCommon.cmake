Using the T option of GNU ar lead to malformed .a archive on NetBSD. Disable it.

--- Source/cmake/OptionsCommon.cmake.orig	2021-09-01 09:16:51 UTC
+++ Source/cmake/OptionsCommon.cmake
@@ -14,10 +14,10 @@ if (USE_THIN_ARCHIVES)
     elseif ("${AR_ERROR}")
         message(WARNING "Error from `ar`: ${AR_ERROR}")
     elseif ("${AR_VERSION}" MATCHES "^GNU ar")
-        set(CMAKE_CXX_ARCHIVE_CREATE "<CMAKE_AR> crT <TARGET> <LINK_FLAGS> <OBJECTS>")
-        set(CMAKE_C_ARCHIVE_CREATE "<CMAKE_AR> crT <TARGET> <LINK_FLAGS> <OBJECTS>")
-        set(CMAKE_CXX_ARCHIVE_APPEND "<CMAKE_AR> rT <TARGET> <LINK_FLAGS> <OBJECTS>")
-        set(CMAKE_C_ARCHIVE_APPEND "<CMAKE_AR> rT <TARGET> <LINK_FLAGS> <OBJECTS>")
+        set(CMAKE_CXX_ARCHIVE_CREATE "<CMAKE_AR> cr <TARGET> <LINK_FLAGS> <OBJECTS>")
+        set(CMAKE_C_ARCHIVE_CREATE "<CMAKE_AR> cr <TARGET> <LINK_FLAGS> <OBJECTS>")
+        set(CMAKE_CXX_ARCHIVE_APPEND "<CMAKE_AR> r <TARGET> <LINK_FLAGS> <OBJECTS>")
+        set(CMAKE_C_ARCHIVE_APPEND "<CMAKE_AR> r <TARGET> <LINK_FLAGS> <OBJECTS>")
     endif ()
 endif ()
 
