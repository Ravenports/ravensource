There is an undiagnosed ARMv6 core dump in this code
as discovered in FreeBSD Bug 183536 when using clang.
Removing this code from ARM builds resolves it.

https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=183536

--- src/fccompat.c.orig	2025-01-17 15:15:05 UTC
+++ src/fccompat.c
@@ -209,7 +209,7 @@ FcRandom(void)
 #else
     random_r (&fcrandbuf, &result);
 #endif
-#elif HAVE_RANDOM
+#elif HAVE_RANDOM && !defined(__arm__)
     static char statebuf[256];
     char *state;
     static FcBool initialized = FcFalse;
