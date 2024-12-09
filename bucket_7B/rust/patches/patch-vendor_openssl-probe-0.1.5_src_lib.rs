--- vendor/openssl-probe-0.1.5/src/lib.rs.orig	2024-11-26 10:12:09 UTC
+++ vendor/openssl-probe-0.1.5/src/lib.rs
@@ -26,11 +26,8 @@ fn cert_dirs_iter() -> impl Iterator<Ite
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
