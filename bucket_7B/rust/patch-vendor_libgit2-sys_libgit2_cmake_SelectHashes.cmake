--- vendor/libgit2-sys/libgit2/cmake/SelectHashes.cmake.orig	2022-11-02 16:21:41 UTC
+++ vendor/libgit2-sys/libgit2/cmake/SelectHashes.cmake
@@ -79,7 +79,7 @@ endif()
 # add library requirements
 if(USE_SHA1 STREQUAL "OpenSSL" OR USE_SHA256 STREQUAL "OpenSSL")
 	if(CMAKE_SYSTEM_NAME MATCHES "FreeBSD")
-		list(APPEND LIBGIT2_PC_LIBS "-lssl")
+		list(APPEND LIBGIT2_PC_LIBS "-lssl_pic")
 	else()
 		list(APPEND LIBGIT2_PC_REQUIRES "openssl")
 	endif()
