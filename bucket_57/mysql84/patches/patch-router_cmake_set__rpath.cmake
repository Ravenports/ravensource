--- router/cmake/set_rpath.cmake.orig	2025-10-31 16:36:07.339593000 +0100
+++ router/cmake/set_rpath.cmake	2025-10-31 16:36:31.325713000 +0100
@@ -27,8 +27,7 @@
   SET(RPATH_ORIGIN "\$ORIGIN")
 ENDIF()
 
-IF(INSTALL_LAYOUT STREQUAL "STANDALONE"
-    OR INSTALL_LAYOUT STREQUAL "SVR4")
+IF(FALSE)
   # rpath for lib/mysqlrouter/ plugins that want to find lib/
   IF(LINUX)
     SET(RPATH_PLUGIN_TO_LIB "${RPATH_ORIGIN}/private")
