--- vendor/openssl-probe/src/lib.rs.orig	2022-06-12 22:29:12 UTC
+++ vendor/openssl-probe/src/lib.rs
@@ -16,9 +16,7 @@ pub fn find_certs_dirs() -> Vec<PathBuf>
     [
         "/var/ssl",
         "/usr/share/ssl",
-        "/usr/local/ssl",
-        "/usr/local/openssl",
-        "/usr/local/share",
+	"@PREFIX@/share",
         "/usr/lib/ssl",
         "/usr/ssl",
         "/etc/openssl",
