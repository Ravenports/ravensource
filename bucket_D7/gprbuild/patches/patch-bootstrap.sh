--- bootstrap.sh.orig	2025-09-15 13:19:27 UTC
+++ bootstrap.sh
@@ -1,6 +1,8 @@
 #!/bin/sh
 # bootstrap.sh - a simple bootstrap for building gprbuild with xmlada
 
+set -x
+
 progname=bootstrap
 
 prefix=/usr/local
@@ -96,7 +98,7 @@ if [ "$UName" = "CYGWI" ] || [ "$UName"
 then
 	cp ${PutUsage}__null.adb ${PutUsage}.adb
 else
-	ln -s $PWD/${PutUsage}__unix.adb ${PutUsage}.adb
+	ln -s $srcdir/${PutUsage}__unix.adb $srcdir/${PutUsage}.adb
 fi
 
 # Build
