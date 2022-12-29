Linux LARGEFILE option does not seem to build.

--- make-config.sh.orig	2022-10-30 19:42:45 UTC
+++ make-config.sh
@@ -523,7 +523,6 @@ case "$sbcl_os" in
         # src/runtime/Config.foo-linux too.
         case "$sbcl_arch" in
 	    mips | arm | x86 | x86-64)
-		printf ' :largefile' >> $ltf
 		;;
         esac
 
