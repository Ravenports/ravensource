--- rapid/plugin/x/mysqlx_configure.cmake.orig	2020-09-23 12:00:04 UTC
+++ rapid/plugin/x/mysqlx_configure.cmake
@@ -42,6 +42,7 @@ CONFIGURE_FILE(${MYSQLX_PROJECT_DIR}/src
 CONFIGURE_FILE(${MYSQLX_PROJECT_DIR}/src/mysqlx_version.h.in
                ${CMAKE_CURRENT_BINARY_DIR}/generated/mysqlx_version.h )
 
+IF(FALSE)
 INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/generated/mysqlx_error.h
         DESTINATION ${INSTALL_INCLUDEDIR}
         COMPONENT Developement)
@@ -53,3 +54,4 @@ INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR
 INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/generated/mysqlx_version.h
         DESTINATION ${INSTALL_INCLUDEDIR}
         COMPONENT Developement)
+ENDIF()
