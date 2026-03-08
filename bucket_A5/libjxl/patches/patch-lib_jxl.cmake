--- lib/jxl.cmake.orig	2026-02-10 13:53:22 UTC
+++ lib/jxl.cmake
@@ -244,6 +244,8 @@ foreach(target IN ITEMS jxl jxl_dec)
       LINK_FLAGS "-Wl,-exported_symbols_list,${CMAKE_CURRENT_SOURCE_DIR}/jxl/jxl_osx.syms")
   elseif(WIN32)
     # Nothing needed here, we use __declspec(dllexport) (jxl_export.h)
+  elseif(CMAKE_SYSTEM_NAME MATCHES "SunOS")
+    # solaris linked does not support --version-script
   else()
   set_property(TARGET ${target} APPEND_STRING PROPERTY
       LINK_FLAGS " -Wl,--version-script=${CMAKE_CURRENT_SOURCE_DIR}/jxl/jxl.version")
