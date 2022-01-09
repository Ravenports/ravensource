--- gnulib/lib/libc-config.h.orig	2021-01-10 18:23:45 UTC
+++ gnulib/lib/libc-config.h
@@ -32,6 +32,11 @@
 
 #include <config.h>
 
+#if defined __FreeBSD__ || defined __DragonFly__
+#undef __nonnull
+#define	__nonnull(...)
+#endif
+
 /* On glibc this includes <features.h> and <sys/cdefs.h> and #defines
    _FEATURES_H, __WORDSIZE, and __set_errno.  On FreeBSD 11 it
    includes <sys/cdefs.h> which defines __nonnull.  Elsewhere it
