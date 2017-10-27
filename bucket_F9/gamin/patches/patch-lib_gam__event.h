--- lib/gam_event.h.orig	2007-07-04 13:36:49 UTC
+++ lib/gam_event.h
@@ -3,6 +3,8 @@
 #ifndef __MD_EVENT_H__
 #define __MD_EVENT_H__
 
+#define	G_CONST_RETURN	const
+
 typedef enum {
 	GAMIN_EVENT_CHANGED = 1 << 4,
 	GAMIN_EVENT_CREATED = 1 << 5,
