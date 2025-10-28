Linux LARGEFILE option does not seem to build.

--- make-config.sh.orig	2025-09-29 07:54:10 UTC
+++ make-config.sh
@@ -301,7 +301,7 @@ case `uname` in
         ;;
     *BSD)
         case `uname` in
-            FreeBSD)
+            FreeBSD|MidnightBSD)
                 sbcl_os="freebsd"
                 ;;
             GNU/kFreeBSD)
@@ -582,7 +582,6 @@ case "$sbcl_os" in
         # src/runtime/Config.foo-linux too.
         case "$sbcl_arch" in
 	    mips | arm | x86 | x86-64)
-		printf ' :largefile' >> $ltf
 		;;
         esac
         if $android
