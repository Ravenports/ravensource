--- cmake/Depends.cmake.orig	2024-12-10 15:28:21 UTC
+++ cmake/Depends.cmake
@@ -43,6 +43,7 @@ else ()
     set (TFDN_ENABLE_STATIC_LINK ${ENABLE_STATIC} CACHE BOOL "" FORCE)
     add_subdirectory (lib/the_Foundation)
     add_library (the_Foundation::the_Foundation ALIAS the_Foundation)
+    find_package (OpenSSL)
     if (NOT OPENSSL_FOUND)
         message (FATAL_ERROR "Lagrange requires OpenSSL for TLS. Please check if pkg-config can find 'openssl'.")
     endif ()
