--- make/autoconf/libraries.m4.orig	2024-04-29 14:34:19 UTC
+++ make/autoconf/libraries.m4
@@ -215,9 +215,9 @@ AC_DEFUN_ONCE([LIB_SETUP_MISC_LIBS],
       ICONV_LDFLAGS="-L/usr/local/lib"
       ICONV_LIBS=-liconv
     elif test "x$OPENJDK_TARGET_OS_ENV" = "xbsd.freebsd"; then
-      ICONV_CFLAGS=-DLIBICONV_PLUG
-      ICONV_LDFLAGS=
-      ICONV_LIBS=
+      ICONV_CFLAGS=%%ICONV_CFLAGS%%
+      ICONV_LDFLAGS=%%ICONV_LDFLAGS%%
+      ICONV_LIBS=%%ICONV_LIBS%%
     else
       ICONV_CFLAGS=
       ICONV_LDFLAGS=
