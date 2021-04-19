--- m4/check-os-options.m4.orig	2021-04-08 08:28:45 UTC
+++ m4/check-os-options.m4
@@ -63,7 +63,6 @@ char buf[1]; getentropy(buf, 1);
 		HOST_ABI=elf
 		# fork detection missing, weak seed on failure
 		# https://svnweb.freebsd.org/base/head/lib/libc/gen/arc4random.c?revision=268642&view=markup
-		USE_BUILTIN_ARC4RANDOM=yes
 		AC_SUBST([PROG_LDADD], ['-lthr'])
 		;;
 	*hpux*)
