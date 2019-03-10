--- cmake/Modules/FindIrrlicht.cmake.orig	2019-03-04 22:43:14 UTC
+++ cmake/Modules/FindIrrlicht.cmake
@@ -7,7 +7,7 @@ set(IRRLICHT_SOURCE_DIR "" CACHE PATH "P
 
 if(NOT IRRLICHT_SOURCE_DIR STREQUAL "")
 	set(IRRLICHT_SOURCE_DIR_INCLUDE
-		"${IRRLICHT_SOURCE_DIR}/include"
+		"${IRRLICHT_SOURCE_DIR}/include/irrlicht"
 	)
 
 	set(IRRLICHT_LIBRARY_NAMES libIrrlicht.a Irrlicht Irrlicht.lib)
@@ -41,6 +41,7 @@ else()
 	find_path(IRRLICHT_INCLUDE_DIR NAMES irrlicht.h
 		PATHS
 		/usr/local/include/irrlicht
+		/raven/include/irrlicht
 		/usr/include/irrlicht
 		/system/develop/headers/irrlicht #Haiku
 	)
@@ -48,6 +49,7 @@ else()
 	find_library(IRRLICHT_LIBRARY NAMES libIrrlicht.so libIrrlicht.a Irrlicht
 		PATHS
 		/usr/local/lib
+		/raven/lib
 		/usr/lib
 		/system/develop/lib # Haiku
 	)
