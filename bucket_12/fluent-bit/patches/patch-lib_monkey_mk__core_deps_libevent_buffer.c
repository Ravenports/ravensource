--- lib/monkey/mk_core/deps/libevent/buffer.c.orig	2025-03-24 22:35:10 UTC
+++ lib/monkey/mk_core/deps/libevent/buffer.c
@@ -108,6 +108,9 @@
 #elif defined(EVENT__HAVE_SENDFILE) && defined(__FreeBSD__)
 #define USE_SENDFILE		1
 #define SENDFILE_IS_FREEBSD	1
+#elif defined(EVENT__HAVE_SENDFILE) && defined(__DragonFly__)
+#define USE_SENDFILE		1
+#define SENDFILE_IS_FREEBSD	1
 #elif defined(EVENT__HAVE_SENDFILE) && defined(__APPLE__)
 #define USE_SENDFILE		1
 #define SENDFILE_IS_MACOSX	1
