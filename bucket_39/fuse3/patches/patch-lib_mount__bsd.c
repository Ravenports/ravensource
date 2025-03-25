--- lib/mount_bsd.c.orig	2025-03-24 12:25:30 UTC
+++ lib/mount_bsd.c
@@ -81,7 +81,7 @@ static const struct fuse_opt fuse_mount_
 	FUSE_DUAL_OPT_KEY("private",		KEY_KERN),
 	FUSE_DUAL_OPT_KEY("neglect_shares",	KEY_KERN),
 	FUSE_DUAL_OPT_KEY("push_symlinks_in",	KEY_KERN),
-#if __FreeBSD_version >= 1200519
+#if (__FreeBSD_version >= 1200519) || defined(__MidnightBSD__)
 	FUSE_DUAL_OPT_KEY("intr",		KEY_KERN),
 #endif
 	/* stock FBSD mountopt parsing routine lets anything be negated... */
