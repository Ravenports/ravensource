--- m4/check-os-options.m4.orig	2025-09-30 14:06:54 UTC
+++ m4/check-os-options.m4
@@ -58,18 +58,15 @@ char buf[1]; getentropy(buf, 1);
 		# Not available on iOS
 		AC_CHECK_HEADER([arpa/telnet.h], [], [BUILD_NC=no])
 		;;
-	*freebsd*)
+	*dragonfly*)
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
+		USE_BUILTIN_ARC4RANDOM=no
+		;;
+	*freebsd*|*midnight*)
+		HOST_OS=freebsd
+		HOST_ABI=elf
+		USE_BUILTIN_ARC4RANDOM=yes
 		AC_SUBST([PROG_LDADD], ['-lthr'])
 		;;
 	*hpux*)
