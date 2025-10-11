--- src/crypto/x509/root_bsd.go.orig	2025-08-27 15:49:40 UTC
+++ src/crypto/x509/root_bsd.go
@@ -8,15 +8,11 @@ package x509
 
 // Possible certificate files; stop after finding one.
 var certFiles = []string{
-	"/usr/local/etc/ssl/cert.pem",            // FreeBSD
-	"/etc/ssl/cert.pem",                      // OpenBSD
-	"/usr/local/share/certs/ca-root-nss.crt", // DragonFly
-	"/etc/openssl/certs/ca-certificates.crt", // NetBSD
+	"/raven/share/certs/ca-root-nss.crt", 
 }
 
 // Possible directories with certificate files; all will be read.
 var certDirectories = []string{
-	"/etc/ssl/certs",         // FreeBSD 12.2+
-	"/usr/local/share/certs", // FreeBSD
-	"/etc/openssl/certs",     // NetBSD
+	"/raven/share/certs",
+	"/etc/ssl/certs",	// FreeBSD 12+
 }
