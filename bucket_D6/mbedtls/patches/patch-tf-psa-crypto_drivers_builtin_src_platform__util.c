--- tf-psa-crypto/drivers/builtin/src/platform_util.c.orig	2025-10-01 15:21:30 UTC
+++ tf-psa-crypto/drivers/builtin/src/platform_util.c
@@ -369,7 +369,7 @@ static int getrandom_wrapper(void *buf,
  *
  * Documentation: https://netbsd.gw.com/cgi-bin/man-cgi?sysctl+7
  */
-#if (defined(__FreeBSD__) || defined(__NetBSD__)) && !defined(HAVE_GETRANDOM)
+#if defined(__FreeBSD__) && !defined(HAVE_GETRANDOM)
 #include <sys/param.h>
 #include <sys/sysctl.h>
 #if defined(KERN_ARND)
