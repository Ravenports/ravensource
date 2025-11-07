--- vendor/openssl-probe-0.1.6/src/lib.rs.orig	2025-11-07 19:52:42 UTC
+++ vendor/openssl-probe-0.1.6/src/lib.rs
@@ -31,11 +31,8 @@ pub fn candidate_cert_dirs() -> impl Ite
     [
         "/var/ssl",
         "/usr/share/ssl",
-        "/usr/local/ssl",
-        "/usr/local/openssl",
-        "/usr/local/etc/openssl",
-        "/usr/local/share",
         "/usr/lib/ssl",
+        "@PREFIX@/share",
         "/usr/ssl",
         "/etc/openssl",
         "/etc/pki/ca-trust/extracted/pem",
