--- cmake/FindUTEMPTER.cmake.orig	2024-08-02 11:15:14 UTC
+++ cmake/FindUTEMPTER.cmake
@@ -29,7 +29,9 @@ else ()
 
     # On FreeBSD for example we have to use ulog-helper
     if (NOT UTEMPTER_EXECUTABLE)
-        find_program (UTEMPTER_EXECUTABLE ulog-helper PATHS /usr/libexec)
+        if(${CMAKE_SYSTEM_NAME} MATCHES "FreeBSD")
+           set(UTEMPTER_EXECUTABLE "/usr/libexec/ulog-helper")
+        endif()
     endif ()
 endif ()
 
