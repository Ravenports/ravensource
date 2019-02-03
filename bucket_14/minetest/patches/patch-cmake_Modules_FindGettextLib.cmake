--- cmake/Modules/FindGettextLib.cmake.orig	2018-06-10 15:18:11 UTC
+++ cmake/Modules/FindGettextLib.cmake
@@ -60,7 +60,7 @@ find_package_handle_standard_args(GetTex
 
 if(GETTEXT_FOUND)
 	# BSD variants require special linkage as they don't use glibc
-	if(${CMAKE_SYSTEM_NAME} MATCHES "BSD")
+	if(${CMAKE_SYSTEM_NAME} MATCHES "BSD|DragonFly")
 		set(GETTEXT_LIBRARY "intl")
 	endif()
 
