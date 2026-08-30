--- vendor/curl-sys-0.4.88+curl-8.20.0/build.rs.orig	2026-07-14 15:13:08 UTC
+++ vendor/curl-sys-0.4.88+curl-8.20.0/build.rs
@@ -106,6 +106,7 @@ fn main() {
         .include("curl/lib")
         .include("curl/include")
         .define("BUILDING_LIBCURL", None)
+        .define("CURL_CA_BUNDLE", "\"@PREFIX@/share/certs/ca-root-nss.crt\"")
         .define("CURL_DISABLE_DICT", None)
         .define("CURL_DISABLE_GOPHER", None)
         .define("CURL_DISABLE_IMAP", None)
