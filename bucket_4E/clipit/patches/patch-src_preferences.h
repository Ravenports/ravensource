--- src/preferences.h.orig	2020-06-11 05:33:56 UTC
+++ src/preferences.h
@@ -80,6 +80,8 @@ void show_preferences(gint tab);
 
 void init_purge_timer();
 
+void init_history_timeout_timer();
+
 G_END_DECLS
 
 #endif
