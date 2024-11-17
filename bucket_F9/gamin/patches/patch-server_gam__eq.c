--- server/gam_eq.c.orig	2007-07-04 13:36:49 UTC
+++ server/gam_eq.c
@@ -124,7 +124,7 @@ gam_eq_flush (gam_eq_t *eq, GamConnDataP
 {
 	gboolean done_work = FALSE;
 	if (!eq)
-		return;
+		return done_work;
 
 #ifdef GAM_EQ_VERBOSE
 	GAM_DEBUG(DEBUG_INFO, "gam_eq: Flushing event queue for %s\n", gam_connection_get_pidname (conn));
