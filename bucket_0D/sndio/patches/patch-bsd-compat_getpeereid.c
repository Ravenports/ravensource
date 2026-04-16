--- bsd-compat/getpeereid.c.orig	2024-08-01 15:36:54 UTC
+++ bsd-compat/getpeereid.c
@@ -21,6 +21,9 @@
 int
 getpeereid(int s, uid_t *ruid, gid_t *rgid)
 {
+  #if defined(__sun)
+	return -1;
+  #else
 	struct ucred cr;
 	socklen_t len = sizeof(cr);
 
@@ -29,5 +32,6 @@ getpeereid(int s, uid_t *ruid, gid_t *rg
 	*ruid = cr.uid;
 	*rgid = cr.gid;
 	return 0;
+  #endif
 }
 #endif
