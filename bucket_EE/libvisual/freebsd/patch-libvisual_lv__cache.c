--- libvisual/lv_cache.c.orig	2017-12-25 23:27:01.606700000 +0100
+++ libvisual/lv_cache.c	2017-12-25 23:28:44.913778000 +0100
@@ -32,7 +32,7 @@
 static int cache_dtor (VisObject *object);
 static int cache_remove_list_entry (VisCache *cache, VisListEntry **le);
 
-static inline void handle_request_reset (VisCache *cache, VisListEntry *le);
+static lv_inline void handle_request_reset (VisCache *cache, VisListEntry *le);
 
 static int cache_dtor (VisObject *object)
 {
@@ -74,7 +74,7 @@
 }
 
 
-static inline void handle_request_reset (VisCache *cache, VisListEntry *le)
+static lv_inline void handle_request_reset (VisCache *cache, VisListEntry *le)
 {
 	VisCacheEntry *centry;
 
