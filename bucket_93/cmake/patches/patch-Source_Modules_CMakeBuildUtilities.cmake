--- Source/Modules/CMakeBuildUtilities.cmake.orig	2023-05-18 17:49:44 UTC
+++ Source/Modules/CMakeBuildUtilities.cmake
@@ -149,11 +149,7 @@ else()
   if(CMAKE_TESTS_CDASH_SERVER)
     set(CMAKE_CURL_TEST_URL "${CMAKE_TESTS_CDASH_SERVER}/user.php")
   endif()
-  set(_CMAKE_USE_OPENSSL_DEFAULT OFF)
-  if(NOT DEFINED CMAKE_USE_OPENSSL AND NOT WIN32 AND NOT APPLE
-      AND CMAKE_SYSTEM_NAME MATCHES "(Linux|FreeBSD)")
     set(_CMAKE_USE_OPENSSL_DEFAULT ON)
-  endif()
   option(CMAKE_USE_OPENSSL "Use OpenSSL." ${_CMAKE_USE_OPENSSL_DEFAULT})
   mark_as_advanced(CMAKE_USE_OPENSSL)
   if(CMAKE_USE_OPENSSL)
