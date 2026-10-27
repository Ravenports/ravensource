--- vendor/openssl-probe-0.2.1/src/lib.rs.orig	2026-10-27 00:43:05 UTC
+++ vendor/openssl-probe-0.2.1/src/lib.rs
@@ -139,32 +139,22 @@ const CERTIFICATE_DIRS: &[&str] = &[
     "/etc/ssl/certs",             // SLES 10, SLES 11
     "/etc/pki/tls/certs",         // Fedora, RHEL
     "/etc/security/certificates", // OpenHarmony, https://developer.huawei.com/consumer/en/doc/best-practices/bpta-network-ca-security#section121091116142117
-];
-
-#[cfg(target_os = "freebsd")]
-const CERTIFICATE_DIRS: &[&str] = &[
-    "/etc/ssl/certs",         // FreeBSD 12.2+,
-    "/usr/local/share/certs", // FreeBSD
+    "@PREFIX@/share/certs",
 ];
 
 #[cfg(any(target_os = "illumos", target_os = "solaris"))]
-const CERTIFICATE_DIRS: &[&str] = &["/etc/certs/CA"];
-
-#[cfg(target_os = "netbsd")]
-const CERTIFICATE_DIRS: &[&str] = &["/etc/openssl/certs"];
+const CERTIFICATE_DIRS: &[&str] = &["/etc/certs/CA", "@PREFIX@/share/certs"];
 
 #[cfg(target_os = "aix")]
 const CERTIFICATE_DIRS: &[&str] = &["/var/ssl/certs"];
 
 #[cfg(not(any(
     target_os = "linux",
-    target_os = "freebsd",
     target_os = "illumos",
     target_os = "solaris",
-    target_os = "netbsd",
     target_os = "aix"
 )))]
-const CERTIFICATE_DIRS: &[&str] = &["/etc/ssl/certs"];
+const CERTIFICATE_DIRS: &[&str] = &["/etc/ssl/certs", "@PREFIX@/share/certs"];
 
 #[cfg(target_os = "linux")]
 const CERTIFICATE_FILE_NAMES: &[&str] = &[
