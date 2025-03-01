--- lib/core-net/client/connect2.c.orig	2025-02-28 06:41:45 UTC
+++ lib/core-net/client/connect2.c
@@ -49,7 +49,7 @@ lws_getaddrinfo46(struct lws *wsi, const
 
 #if !defined(__ANDROID__)
 		hints.ai_family = AF_UNSPEC;
-#if !defined(__OpenBSD__) && !defined(__OPENBSD)
+#if !defined(__OpenBSD__) && !defined(__OPENBSD) && !defined(__NetBSD__)
 		hints.ai_flags = AI_V4MAPPED;
 #endif
 #endif
