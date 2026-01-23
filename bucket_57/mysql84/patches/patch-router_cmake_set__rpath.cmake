--- router/cmake/set_rpath.cmake.orig	2025-12-15 11:53:49 UTC
+++ router/cmake/set_rpath.cmake
@@ -27,8 +27,7 @@ ELSE()
   SET(RPATH_ORIGIN "\$ORIGIN")
 ENDIF()
 
-IF(INSTALL_LAYOUT STREQUAL "STANDALONE"
-    OR INSTALL_LAYOUT STREQUAL "SVR4")
+IF(FALSE)
   # rpath for lib/mysqlrouter/ plugins that want to find lib/
   IF(LINUX)
     SET(RPATH_PLUGIN_TO_LIB "${RPATH_ORIGIN}/private")
