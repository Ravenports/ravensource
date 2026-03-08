--- lib/jxl_threads.cmake.orig	2026-02-10 13:53:22 UTC
+++ lib/jxl_threads.cmake
@@ -45,6 +45,8 @@ if(APPLE)
       LINK_FLAGS "-Wl,-exported_symbols_list,${CMAKE_CURRENT_SOURCE_DIR}/jxl/jxl_osx.syms")
 elseif(WIN32)
 # Nothing needed here, we use __declspec(dllexport) (jxl_threads_export.h)
+elseif(CMAKE_SYSTEM_NAME MATCHES "SunOS")
+# version-script not supported by solaris linker
 else()
   set_property(TARGET jxl_threads APPEND_STRING PROPERTY
       LINK_FLAGS " -Wl,--version-script=${CMAKE_CURRENT_SOURCE_DIR}/jxl/jxl.version")
