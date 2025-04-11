--- src/nxt_kqueue_engine.c.orig	2025-02-27 22:02:21 UTC
+++ src/nxt_kqueue_engine.c
@@ -39,7 +39,7 @@
 #endif
 
 
-#if (NXT_NETBSD)
+#if (0)
 /* NetBSD defines the kevent.udata field as intptr_t. */
 
 #define nxt_kevent_set_udata(udata)  (intptr_t) (udata)
