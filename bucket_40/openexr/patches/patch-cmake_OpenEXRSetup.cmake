--- cmake/OpenEXRSetup.cmake.orig	2026-02-21 20:42:03 UTC
+++ cmake/OpenEXRSetup.cmake
@@ -101,7 +101,7 @@ set(CMAKE_INCLUDE_CURRENT_DIR ON)
 # (if you should choose to install those)
 # Don't override if the user has set it and don't save it in the cache
 if (NOT DEFINED CMAKE_DEBUG_POSTFIX)
-  set(CMAKE_DEBUG_POSTFIX "_d")
+#  set(CMAKE_DEBUG_POSTFIX "_d")
 endif()
 
 if(NOT OPENEXR_IS_SUBPROJECT)
