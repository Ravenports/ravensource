--- src/event/event_epoll.c.orig	2025-10-24 16:57:11 UTC
+++ src/event/event_epoll.c
@@ -89,7 +89,7 @@ DISPATCH_ALWAYS_INLINE
 static inline uint32_t
 _dispatch_muxnote_armed_events(dispatch_muxnote_t dmn)
 {
-	return dmn->dmn_events & ~dmn->dmn_disarmed_events;
+	return dmn->dmn_events & (uint32_t)~dmn->dmn_disarmed_events;
 }
 
 DISPATCH_ALWAYS_INLINE
