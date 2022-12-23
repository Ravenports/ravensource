--- sysdeps/freebsd/mountlist.c.orig	2019-02-04 20:15:22 UTC
+++ sysdeps/freebsd/mountlist.c
@@ -99,6 +99,7 @@ static gboolean ignore_mount_entry(const
 		"mfs",
 		"none",
 		"nfs",
+		"null",
 		"nullfs",
 		"nwfs",
 		"portalfs",
