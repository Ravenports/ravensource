--- router/cmake/set_rpath.cmake.orig	2019-01-25 22:33:03 UTC
+++ router/cmake/set_rpath.cmake
@@ -81,8 +81,7 @@ ELSE()
 ENDIF()
 
 SET(CMAKE_INSTALL_RPATH)
-IF(INSTALL_LAYOUT STREQUAL "STANDALONE" OR INSTALL_LAYOUT STREQUAL "DEFAULT" OR
-   INSTALL_LAYOUT STREQUAL "WIN" OR INSTALL_LAYOUT STREQUAL "SVR4")
+IF(FALSE)
   # rpath for lib/mysqlrouter/ plugins that want to find lib/
   SET(RPATH_PLUGIN_TO_LIB "${RPATH_ORIGIN}/../")
   SET(RPATH_PLUGIN_TO_PLUGIN "${RPATH_ORIGIN}/")
