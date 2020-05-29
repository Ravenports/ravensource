Poorly tested feature the day before release.  Wow.

--- src/perl/nxt_perl_psgi.c.orig	2020-05-28 16:04:00 UTC
+++ src/perl/nxt_perl_psgi.c
@@ -119,10 +119,8 @@ NXT_EXPORT nxt_app_module_t  nxt_app_mod
     nxt_string("perl"),
     PERL_VERSION_STRING,
 
-#if (NXT_HAVE_ISOLATION_ROOTFS)
     NULL,
     0,
-#endif
 
     NULL,
     nxt_perl_psgi_start,
