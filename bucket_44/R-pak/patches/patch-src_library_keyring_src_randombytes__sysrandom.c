--- src/library/keyring/src/randombytes_sysrandom.c.orig	2025-10-08 12:07:32 UTC
+++ src/library/keyring/src/randombytes_sysrandom.c
@@ -30,6 +30,8 @@
 #   define HAVE_LINUX_COMPATIBLE_GETRANDOM
 #  endif
 # endif
+#elif defined(__MidnightBSD__)
+# include <sys/random.h>
 #elif defined(__FreeBSD__) || defined(__DragonFly__)
 # include <sys/param.h>
 # if (defined(__FreeBSD_version) && __FreeBSD_version >= 1200000) || \
