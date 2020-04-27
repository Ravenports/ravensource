--- cmake/plugin.cmake.orig	2020-03-26 13:31:45 UTC
+++ cmake/plugin.cmake
@@ -224,9 +224,6 @@ MACRO(MYSQL_ADD_PLUGIN)
       MYSQL_INSTALL_TARGETS(${target}
         DESTINATION ${INSTALL_PLUGINDIR}
         COMPONENT ${INSTALL_COMPONENT})
-      INSTALL_DEBUG_TARGET(${target}
-        DESTINATION ${INSTALL_PLUGINDIR}/debug
-        COMPONENT ${INSTALL_COMPONENT})
     ENDIF()
   ELSE()
     IF(WITHOUT_${plugin})
