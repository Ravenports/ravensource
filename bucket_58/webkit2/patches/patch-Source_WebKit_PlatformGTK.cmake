--- Source/WebKit/PlatformGTK.cmake.orig	2021-09-01 09:16:51 UTC
+++ Source/WebKit/PlatformGTK.cmake
@@ -34,7 +34,7 @@ add_definitions(-DLOCALEDIR="${CMAKE_INS
 add_definitions(-DDATADIR="${CMAKE_INSTALL_FULL_DATADIR}")
 add_definitions(-DLIBDIR="${LIB_INSTALL_DIR}")
 
-if (NOT DEVELOPER_MODE AND NOT CMAKE_SYSTEM_NAME MATCHES "Darwin")
+if (NOT DEVELOPER_MODE AND NOT CMAKE_SYSTEM_NAME MATCHES "Darwin|SunOS")
     WEBKIT_ADD_TARGET_PROPERTIES(WebKit LINK_FLAGS "-Wl,--version-script,${CMAKE_CURRENT_SOURCE_DIR}/webkitglib-symbols.map")
 endif ()
 
