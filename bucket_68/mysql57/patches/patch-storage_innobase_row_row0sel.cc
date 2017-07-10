--- storage/innobase/row/row0sel.cc.orig	2017-03-18 07:45:14 UTC
+++ storage/innobase/row/row0sel.cc
@@ -5163,7 +5163,7 @@ rec_loop:
 		reporting due to search views etc. */
 		if (prev_rec != NULL
 		    && prebuilt->m_mysql_handler->end_range != NULL
-		    && prebuilt->idx_cond == false && end_loop >= 100) {
+		    && !prebuilt->idx_cond && end_loop >= 100) {
 
 			dict_index_t*	key_index = prebuilt->index;
 			bool		clust_templ_for_sec = false;
