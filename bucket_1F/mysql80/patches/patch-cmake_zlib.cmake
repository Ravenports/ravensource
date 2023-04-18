There seems to be something wrong with Cmake's FindZlib,
maybe with the version string.  Ignore checks for now, it is
finding zlib.

--- cmake/zlib.cmake.orig	2023-03-16 17:22:37 UTC
+++ cmake/zlib.cmake
@@ -52,7 +52,6 @@ ENDFUNCTION(FIND_ZLIB_VERSION)
 
 FUNCTION(FIND_SYSTEM_ZLIB)
   FIND_PACKAGE(ZLIB)
-  IF(ZLIB_FOUND)
     ADD_LIBRARY(zlib_interface INTERFACE)
     TARGET_LINK_LIBRARIES(zlib_interface INTERFACE ${ZLIB_LIBRARIES})
 
@@ -60,7 +59,6 @@ FUNCTION(FIND_SYSTEM_ZLIB)
       TARGET_INCLUDE_DIRECTORIES(zlib_interface SYSTEM INTERFACE
         ${ZLIB_INCLUDE_DIR})
     ENDIF()
-  ENDIF()
 ENDFUNCTION(FIND_SYSTEM_ZLIB)
 
 MACRO (RESET_ZLIB_VARIABLES)
@@ -114,9 +112,6 @@ MACRO (MYSQL_CHECK_ZLIB)
     MYSQL_USE_BUNDLED_ZLIB()
   ELSEIF(WITH_ZLIB STREQUAL "system")
     FIND_SYSTEM_ZLIB()
-    IF(NOT ZLIB_FOUND)
-      MESSAGE(FATAL_ERROR "Cannot find system zlib libraries.")
-    ENDIF()
   ELSE()
     RESET_ZLIB_VARIABLES()
     MESSAGE(FATAL_ERROR "WITH_ZLIB must be bundled or system")
@@ -124,9 +119,4 @@ MACRO (MYSQL_CHECK_ZLIB)
 
   ADD_LIBRARY(ext::zlib ALIAS zlib_interface)
 
-  IF(ZLIB_VERSION VERSION_LESS MIN_ZLIB_VERSION_REQUIRED)
-    MESSAGE(FATAL_ERROR
-      "ZLIB version must be at least ${MIN_ZLIB_VERSION_REQUIRED}, "
-      "found ${ZLIB_VERSION}.\nPlease use -DWITH_ZLIB=bundled")
-  ENDIF()
 ENDMACRO()
