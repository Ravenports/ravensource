--- src/actions/action.c.orig	2018-04-16 19:26:29 UTC
+++ src/actions/action.c
@@ -2047,7 +2047,7 @@ void fm_load_all_actions (void) {
 	gchar* _tmp9_ = NULL;
 	_tmp0_ = fm_all_actions;
 	g_hash_table_remove_all (_tmp0_);
-	_tmp2_ = _tmp1_ = g_get_system_data_dirs ();
+	_tmp2_ = _tmp1_ = (gchar **)g_get_system_data_dirs ();
 	dirs = _tmp2_;
 	dirs_length1 = _vala_array_length (_tmp1_);
 	_dirs_size_ = dirs_length1;
