--- Source/WebKit/PlatformGTK.cmake.orig	2023-03-15 13:59:47 UTC
+++ Source/WebKit/PlatformGTK.cmake
@@ -40,7 +40,7 @@ add_definitions(-DDATADIR="${CMAKE_INSTA
 add_definitions(-DLIBDIR="${LIB_INSTALL_DIR}")
 add_definitions(-DPKGLIBDIR="${LIB_INSTALL_DIR}/webkit${WEBKITGTK_API_INFIX}gtk-${WEBKITGTK_API_VERSION}")
 
-if (NOT DEVELOPER_MODE AND NOT CMAKE_SYSTEM_NAME MATCHES "Darwin")
+if (NOT DEVELOPER_MODE AND NOT CMAKE_SYSTEM_NAME MATCHES "Darwin|SunOS")
     WEBKIT_ADD_TARGET_PROPERTIES(WebKit LINK_FLAGS "-Wl,--version-script,${CMAKE_CURRENT_SOURCE_DIR}/webkitglib-symbols.map")
 endif ()
 
