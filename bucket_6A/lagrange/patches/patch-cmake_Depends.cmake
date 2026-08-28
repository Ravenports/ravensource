--- cmake/Depends.cmake.orig	2026-08-28 15:39:26.481797000 +0200
+++ cmake/Depends.cmake	2026-08-28 15:41:03.279168000 +0200
@@ -69,6 +69,7 @@
         find_package (OpenSSL QUIET)
         find_package (ZLIB QUIET)
     endif ()
+    find_package (OpenSSL)
     if (NOT OPENSSL_FOUND)
         message (FATAL_ERROR "Lagrange requires OpenSSL for TLS. Please check if pkg-config can find 'openssl'.")
     endif ()
