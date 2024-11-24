--- libgamin/gam_fork.h.orig	2007-07-04 13:36:48 UTC
+++ libgamin/gam_fork.h
@@ -32,6 +32,9 @@ extern "C" {
 #endif
 
 int		gamin_fork_server	(const char *fam_client_id);
+#ifdef RUN_AS_EUID
+int		gamin_drop_privileges	(int to_uid, int to_gid);
+#endif
 
 #ifdef __cplusplus
 }
