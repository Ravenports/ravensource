--- gnulib/lib/libc-config.h.orig	2026-09-29 22:03:49 UTC
+++ gnulib/lib/libc-config.h
@@ -35,6 +35,11 @@
 
 #include <config.h>
 
+#if defined __FreeBSD__ || defined __DragonFly__
+#undef __nonnull
+#define	__nonnull(...)
+#endif
+
 /* On glibc this includes <features.h> and <sys/cdefs.h> and #defines
    _FEATURES_H, __WORDSIZE, and __set_errno.  On FreeBSD 11 and
    DragonFlyBSD 5.9 it includes <sys/cdefs.h> which defines __nonnull.
