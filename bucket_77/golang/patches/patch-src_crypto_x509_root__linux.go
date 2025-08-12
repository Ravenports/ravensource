--- src/crypto/x509/root_linux.go.orig	2025-07-02 21:47:15 UTC
+++ src/crypto/x509/root_linux.go
@@ -8,18 +8,13 @@ import "internal/goos"
 
 // Possible certificate files; stop after finding one.
 var certFiles = []string{
-	"/etc/ssl/certs/ca-certificates.crt",                // Debian/Ubuntu/Gentoo etc.
-	"/etc/pki/tls/certs/ca-bundle.crt",                  // Fedora/RHEL 6
-	"/etc/ssl/ca-bundle.pem",                            // OpenSUSE
-	"/etc/pki/tls/cacert.pem",                           // OpenELEC
-	"/etc/pki/ca-trust/extracted/pem/tls-ca-bundle.pem", // CentOS/RHEL 7
-	"/etc/ssl/cert.pem",                                 // Alpine Linux
+	"/raven/share/certs/ca-root-nss.crt",
 }
 
 // Possible directories with certificate files; all will be read.
 var certDirectories = []string{
+	"/raven/share/certs",
 	"/etc/ssl/certs",     // SLES10/SLES11, https://golang.org/issue/12139
-	"/etc/pki/tls/certs", // Fedora/RHEL
 }
 
 func init() {
