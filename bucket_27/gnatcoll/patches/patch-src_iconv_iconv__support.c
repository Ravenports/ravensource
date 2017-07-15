--- src/iconv/iconv_support.c.orig	2017-05-11 18:04:51 UTC
+++ src/iconv/iconv_support.c
@@ -6,6 +6,7 @@
 #include <iconv.h>
 #include <errno.h>
 #include <locale.h>
+#include <sys/param.h>
 
 const int gnatcoll_errno_einval = EINVAL;
 const int gnatcoll_errno_e2big  = E2BIG;
@@ -25,7 +26,8 @@ int gnatcoll_iconv_close(iconv_t cd) {
    return iconv_close (cd);
 }
 
-#if _LIBICONV_VERSION >= 0x010D
+#if defined (__DragonFly__) || \
+   (defined (__FreeBSD__) && __FreeBSD_version < 1001514)
 size_t gnatcoll_iconv
    (iconv_t cd,  char** inbuf, size_t *inbytesleft, char** outbuf,
     size_t *outbytesleft)
