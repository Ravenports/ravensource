--- cmake/plugin.cmake.orig	2019-01-25 22:33:03 UTC
+++ cmake/plugin.cmake
@@ -231,9 +231,6 @@ MACRO(MYSQL_ADD_PLUGIN)
       MYSQL_INSTALL_TARGETS(${target}
         DESTINATION ${INSTALL_PLUGINDIR}
         COMPONENT ${INSTALL_COMPONENT})
-      INSTALL_DEBUG_TARGET(${target}
-        DESTINATION ${INSTALL_PLUGINDIR}/debug
-        COMPONENT ${INSTALL_COMPONENT})
       # For internal testing in PB2, append collections files
       IF(DEFINED ENV{PB2WORKDIR})
         PLUGIN_APPEND_COLLECTIONS(${plugin})
