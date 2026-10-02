--- cmake/Depends.cmake.orig	2026-09-03 05:47:07 UTC
+++ cmake/Depends.cmake
@@ -69,6 +69,7 @@ else ()
         find_package (OpenSSL QUIET)
         find_package (ZLIB QUIET)
     endif ()
+    find_package (OpenSSL)
     if (NOT OPENSSL_FOUND)
         message (FATAL_ERROR "Lagrange requires OpenSSL for TLS. Please check if pkg-config can find 'openssl'.")
     endif ()
