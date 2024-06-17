--- vendor/curl-sys-0.4.72+curl-8.6.0/build.rs.orig	2006-07-24 01:21:28 UTC
+++ vendor/curl-sys-0.4.72+curl-8.6.0/build.rs
@@ -109,6 +109,7 @@ fn main() {
         .include("curl/lib")
         .include("curl/include")
         .define("BUILDING_LIBCURL", None)
+        .define("CURL_CA_BUNDLE", "\"@PREFIX@/share/certs/ca-root-nss.crt\"")
         .define("CURL_DISABLE_DICT", None)
         .define("CURL_DISABLE_GOPHER", None)
         .define("CURL_DISABLE_IMAP", None)
