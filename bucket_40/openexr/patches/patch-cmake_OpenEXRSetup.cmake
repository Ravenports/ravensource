--- cmake/OpenEXRSetup.cmake.orig	2021-04-01 18:25:21 UTC
+++ cmake/OpenEXRSetup.cmake
@@ -67,9 +67,6 @@ set(OPENEXR_OUTPUT_SUBDIR OpenEXR CACHE
 # but is pretty harmless to set globally
 set(CMAKE_INCLUDE_CURRENT_DIR ON)
 
-# Suffix for debug configuration libraries
-# (if you should choose to install those)
-set(CMAKE_DEBUG_POSTFIX "_d" CACHE STRING "Suffix for debug builds")
 
 if(NOT OPENEXR_IS_SUBPROJECT)
   # Usual cmake option to build shared libraries or not, only overriden if OpenEXR is a top level project,
