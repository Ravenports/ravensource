--- vendor/curl-sys-0.4.82+curl-8.14.1/build.rs.orig	2025-09-14 15:05:11 UTC
+++ vendor/curl-sys-0.4.82+curl-8.14.1/build.rs
@@ -117,6 +117,7 @@ fn main() {
         .include("curl/lib")
         .include("curl/include")
         .define("BUILDING_LIBCURL", None)
+        .define("CURL_CA_BUNDLE", "\"@PREFIX@/share/certs/ca-root-nss.crt\"")
         .define("CURL_DISABLE_DICT", None)
         .define("CURL_DISABLE_GOPHER", None)
         .define("CURL_DISABLE_IMAP", None)
