--- lib/mount_bsd.c.intermediate	2024-11-26 13:24:03 UTC
+++ lib/mount_bsd.c
@@ -207,7 +207,8 @@ void fuse_kern_unmount(const char *mount
 /* Check if kernel is doing init in background */
 static int init_backgrounded(void)
 {
-	unsigned ibg, len;
+	unsigned ibg;
+	size_t len;
 
 	len = sizeof(ibg);
 
