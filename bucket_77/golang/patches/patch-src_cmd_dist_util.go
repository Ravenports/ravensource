--- src/cmd/dist/util.go.orig	2017-08-24 21:50:31 UTC
+++ src/cmd/dist/util.go
@@ -409,9 +409,6 @@ func main() {
 		// Even on 64-bit platform, darwin uname -m prints i386.
 		// We don't support any of the OS X versions that run on 32-bit-only hardware anymore.
 		gohostarch = "amd64"
-	case "freebsd":
-		// Since FreeBSD 10 gcc is no longer part of the base system.
-		defaultclang = true
 	case "solaris":
 		// Even on 64-bit platform, solaris uname -m prints i86pc.
 		out := run("", CheckExit, "isainfo", "-n")
