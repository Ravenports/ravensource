--- lib/mount_bsd.c.orig	2023-07-05 10:14:33 UTC
+++ lib/mount_bsd.c
@@ -8,7 +8,7 @@
   See the file COPYING.LIB.
 */
 
-#include "config.h"
+#include "fuse_config.h"
 #include "fuse_i.h"
 #include "fuse_misc.h"
 #include "fuse_opt.h"
@@ -19,7 +19,9 @@
 #include <sys/stat.h>
 #include <sys/wait.h>
 #include <sys/sysctl.h>
+#if !defined(__NetBSD__)
 #include <sys/user.h>
+#endif
 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
@@ -86,7 +88,7 @@ static const struct fuse_opt fuse_mount_
 	FUSE_DUAL_OPT_KEY("neglect_shares",	KEY_KERN),
 	FUSE_DUAL_OPT_KEY("push_symlinks_in",	KEY_KERN),
 	FUSE_OPT_KEY("nosync_unmount",		KEY_KERN),
-#if __FreeBSD_version >= 1200519
+#if (__FreeBSD_version >= 1200519) || defined(__MidnightBSD__)
 	FUSE_DUAL_OPT_KEY("intr",		KEY_KERN),
 #endif
 	/* stock FBSD mountopt parsing routine lets anything be negated... */
