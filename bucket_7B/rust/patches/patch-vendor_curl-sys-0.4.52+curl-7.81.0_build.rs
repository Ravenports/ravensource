--- vendor/curl-sys-0.4.52+curl-7.81.0/build.rs.orig	2025-06-23 19:24:54 UTC
+++ vendor/curl-sys-0.4.52+curl-7.81.0/build.rs
@@ -111,6 +111,7 @@ fn main() {
         .include("curl/lib")
         .include("curl/include")
         .define("BUILDING_LIBCURL", None)
+        .define("CURL_CA_BUNDLE", "\"@PREFIX@/share/certs/ca-root-nss.crt\"")
         .define("CURL_DISABLE_DICT", None)
         .define("CURL_DISABLE_GOPHER", None)
         .define("CURL_DISABLE_IMAP", None)
