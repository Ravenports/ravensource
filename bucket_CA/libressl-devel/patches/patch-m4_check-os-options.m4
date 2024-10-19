--- m4/check-os-options.m4.orig	2024-05-28 13:25:41 UTC
+++ m4/check-os-options.m4
@@ -58,18 +58,15 @@ char buf[1]; getentropy(buf, 1);
 		# Not available on iOS
 		AC_CHECK_HEADER([arpa/telnet.h], [], [BUILD_NC=no])
 		;;
+	*dragonfly*)
+		HOST_OS=freebsd
+		HOST_ABI=elf
+		USE_BUILTIN_ARC4RANDOM=no
+		;;
 	*freebsd*)
 		HOST_OS=freebsd
 		HOST_ABI=elf
-		AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
-#include <sys/param.h>
-#if __FreeBSD_version < 1200000
-        undefined
-#endif
-                       ]], [[]])],
-                       [ USE_BUILTIN_ARC4RANDOM=no ],
-                       [ USE_BUILTIN_ARC4RANDOM=yes ]
-		)
+		USE_BUILTIN_ARC4RANDOM=yes
 		AC_SUBST([PROG_LDADD], ['-lthr'])
 		;;
 	*hpux*)
