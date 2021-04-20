--- router/cmake/set_rpath.cmake.orig	2021-03-22 08:44:50 UTC
+++ router/cmake/set_rpath.cmake
@@ -27,8 +27,7 @@ ELSE()
 ENDIF()
 
 SET(CMAKE_INSTALL_RPATH)
-IF(INSTALL_LAYOUT STREQUAL "STANDALONE"
-    OR INSTALL_LAYOUT STREQUAL "SVR4")
+IF(FALSE)
   # rpath for lib/mysqlrouter/ plugins that want to find lib/
   IF(LINUX)
     SET(RPATH_PLUGIN_TO_LIB "${RPATH_ORIGIN}/private")
