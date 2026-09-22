Work around multibyte bug on NetBSD (standards/60369)

--- p11-kit/gen-pkcs11-gnu.sh.orig	2023-10-24 12:58:49 UTC
+++ p11-kit/gen-pkcs11-gnu.sh
@@ -1,5 +1,8 @@
 #!/bin/sh
 
+LC_ALL=C
+export LC_ALL
+
 source="$1"
 target="$2"
 
