--- lib/monkey/mk_core/deps/libevent/kqueue.c.orig	2024-12-19 17:21:21 UTC
+++ lib/monkey/mk_core/deps/libevent/kqueue.c
@@ -50,7 +50,7 @@
 /* Some platforms apparently define the udata field of struct kevent as
  * intptr_t, whereas others define it as void*.  There doesn't seem to be an
  * easy way to tell them apart via autoconf, so we need to use OS macros. */
-#if defined(EVENT__HAVE_INTTYPES_H) && !defined(__OpenBSD__) && !defined(__FreeBSD__) && !defined(__darwin__) && !defined(__APPLE__) && !defined(__CloudABI__)
+#if defined(EVENT__HAVE_INTTYPES_H) && !defined(__OpenBSD__) && !defined(__FreeBSD__) && !defined(__darwin__) && !defined(__APPLE__) && !defined(__CloudABI__) && !defined(__DragonFly__) && !defined(__NetBSD__)
 #define PTR_TO_UDATA(x)	((intptr_t)(x))
 #define INT_TO_UDATA(x) ((intptr_t)(x))
 #else
