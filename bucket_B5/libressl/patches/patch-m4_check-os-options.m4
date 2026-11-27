--- m4/check-os-options.m4.orig	2026-02-07 22:51:39 UTC
+++ m4/check-os-options.m4
@@ -76,15 +76,6 @@ char buf[1]; getentropy(buf, 1);
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
 		AC_SUBST([PROG_LDADD], ['-lthr'])
 		;;
 	*hpux*)
