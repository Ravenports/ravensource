--- utils.c.orig	2024-09-20 07:46:46 UTC
+++ utils.c
@@ -33,6 +33,14 @@
 #include <stdint.h>
 #include <string.h>
 #include <unistd.h>
+#include <limits.h>
+
+#ifdef __DragonFly__
+#include <vfs/ufs/dir.h>
+#endif
+#ifdef __sun
+#include <fcntl.h>
+#endif
 
 #ifdef HAVE_LIBPROCSTAT_H
 #include <sys/sysctl.h>
@@ -182,6 +190,9 @@ scandir_sub(char *path, int off, int rem
 	DIR *dir;
 	struct dirent *ent;
 	int ret = 0;
+#if defined(__sun)
+	struct stat st;
+#endif
 
 	dir = opendir(path);
 	if (dir == NULL)
@@ -200,7 +211,17 @@ scandir_sub(char *path, int off, int rem
 		off += len;
 		rem -= len;
 
+#if defined(__sun)
+		if (fstatat(dirfd(dir), ent->d_name, &st, AT_SYMLINK_NOFOLLOW) != 0) {
+			off -= len;
+			rem += len;
+			continue;
+		}
+
+		if ((ctx->recursive) && S_ISDIR(st.st_mode)) {
+#else
 		if ((ctx->recursive) && (ent->d_type == DT_DIR)) {
+#endif
 			if (rem < 1)
 				break;
 			path[off] = '/';
@@ -212,7 +233,11 @@ scandir_sub(char *path, int off, int rem
 			off--;
 			rem++;
 		} else {
+#if defined(__sun)
+			ret = (ctx->cb)(path, st.st_mode, ctx->args);
+#else
 			ret = (ctx->cb)(path, DTTOIF(ent->d_type), ctx->args);
+#endif
 		}
 		off -= len;
 		rem += len;
