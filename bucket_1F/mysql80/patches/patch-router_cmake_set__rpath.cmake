--- router/cmake/set_rpath.cmake.orig	2019-12-09 19:53:17 UTC
+++ router/cmake/set_rpath.cmake
@@ -27,8 +27,7 @@ ELSE()
 ENDIF()
 
 SET(CMAKE_INSTALL_RPATH)
-IF(INSTALL_LAYOUT STREQUAL "STANDALONE"
-    OR INSTALL_LAYOUT STREQUAL "SVR4")
+IF(FALSE)
   # rpath for lib/mysqlrouter/ plugins that want to find lib/
   SET(RPATH_PLUGIN_TO_LIB "${RPATH_ORIGIN}/../")
   SET(RPATH_PLUGIN_TO_PLUGIN "${RPATH_ORIGIN}/")
