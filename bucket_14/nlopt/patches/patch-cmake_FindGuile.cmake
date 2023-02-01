--- cmake/FindGuile.cmake.orig	2021-12-03 18:38:01 UTC
+++ cmake/FindGuile.cmake
@@ -68,20 +68,20 @@ find_program(GUILE_EXECUTABLE
            )
 
 find_program(GUILE_CONFIG_EXECUTABLE
-              NAMES guile-config
+              NAMES pkg-config
            )
 
 
 if (GUILE_CONFIG_EXECUTABLE)
-  execute_process (COMMAND ${GUILE_CONFIG_EXECUTABLE} info prefix
+  execute_process (COMMAND ${GUILE_CONFIG_EXECUTABLE} --variable=prefix guile-3.0
                     OUTPUT_VARIABLE GUILE_ROOT_DIR
                     OUTPUT_STRIP_TRAILING_WHITESPACE)
 
-  execute_process (COMMAND ${GUILE_CONFIG_EXECUTABLE} info sitedir
+  execute_process (COMMAND ${GUILE_CONFIG_EXECUTABLE} --variable=sitedir guile-3.0
                     OUTPUT_VARIABLE GUILE_SITE_DIR
                     OUTPUT_STRIP_TRAILING_WHITESPACE)
 
-  execute_process (COMMAND ${GUILE_CONFIG_EXECUTABLE} info extensiondir
+  execute_process (COMMAND ${GUILE_CONFIG_EXECUTABLE} --variable=extensiondir guile-3.0
                     OUTPUT_VARIABLE GUILE_EXTENSION_DIR
                     OUTPUT_STRIP_TRAILING_WHITESPACE)
 endif ()
