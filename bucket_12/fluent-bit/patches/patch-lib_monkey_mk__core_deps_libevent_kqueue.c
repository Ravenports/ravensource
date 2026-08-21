--- lib/monkey/mk_core/deps/libevent/kqueue.c.orig	2026-08-15 03:52:07 UTC
+++ lib/monkey/mk_core/deps/libevent/kqueue.c
@@ -54,7 +54,7 @@
 #if defined(__NetBSD__)
 #define PTR_TO_UDATA(x) ((__typeof__(((struct kevent *)0)->udata))(x))
 #define INT_TO_UDATA(x) ((__typeof__(((struct kevent *)0)->udata))(intptr_t)(x))
-#elif defined(EVENT__HAVE_INTTYPES_H) && !defined(__OpenBSD__) && !defined(__FreeBSD__) && !defined(__darwin__) && !defined(__APPLE__) && !defined(__CloudABI__)
+#elif defined(EVENT__HAVE_INTTYPES_H) && !defined(__OpenBSD__) && !defined(__FreeBSD__) && !defined(__darwin__) && !defined(__APPLE__) && !defined(__CloudABI__) && !defined(__DragonFly__)
 #define PTR_TO_UDATA(x)	((intptr_t)(x))
 #define INT_TO_UDATA(x) ((intptr_t)(x))
 #else
