--- cmake/Modules/ECMGeneratePriFile.cmake.orig	2026-04-29 16:10:01 UTC
+++ cmake/Modules/ECMGeneratePriFile.cmake
@@ -112,7 +112,7 @@ if(KDE_INSTALL_USE_QT_SYS_PATHS OR _shou
   endif()
   set(ECM_MKSPECS_INSTALL_DIR ${mkspecs_install_dir} CACHE PATH "The directory where mkspecs will be installed to.")
 else()
-  set(ECM_MKSPECS_INSTALL_DIR mkspecs/modules CACHE PATH "The directory where mkspecs will be installed to.")
+    set(ECM_MKSPECS_INSTALL_DIR ${QT_MKSPECDIR_REL}/modules CACHE PATH "The directory where mkspecs will be installed to.")
 endif()
 
 function(ECM_GENERATE_PRI_FILE)
