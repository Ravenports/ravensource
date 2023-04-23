Linux LARGEFILE option does not seem to build.

--- make-config.sh.orig	2023-03-28 19:42:52 UTC
+++ make-config.sh
@@ -286,7 +286,7 @@ case `uname` in
         ;;
     *BSD)
         case `uname` in
-            FreeBSD)
+            FreeBSD|MidnightBSD)
                 sbcl_os="freebsd"
                 ;;
             GNU/kFreeBSD)
@@ -523,7 +523,6 @@ case "$sbcl_os" in
         # src/runtime/Config.foo-linux too.
         case "$sbcl_arch" in
 	    mips | arm | x86 | x86-64)
-		printf ' :largefile' >> $ltf
 		;;
         esac
 
