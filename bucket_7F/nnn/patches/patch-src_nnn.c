--- src/nnn.c.orig	2025-08-08 16:08:24 UTC
+++ src/nnn.c
@@ -46,7 +46,7 @@
 #include <sys/resource.h>
 #include <sys/stat.h>
 #include <sys/statvfs.h>
-#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(__APPLE__)
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(__APPLE__) || defined(__DragonFly__)
 #include <sys/types.h>
 #include <sys/event.h>
 #include <sys/time.h>
@@ -64,7 +64,7 @@
 #define NCURSES_WIDECHAR 1
 #endif
 #elif defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) \
-	|| defined(__APPLE__) || defined(__sun)
+	|| defined(__APPLE__) || defined(__sun) || defined(__DragonFly__)
 #ifndef _XOPEN_SOURCE_EXTENDED
 #define _XOPEN_SOURCE_EXTENDED
 #endif
@@ -228,7 +228,7 @@
 
 #ifndef SED
 /* BSDs or Solaris or SunOS */
-#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(__APPLE__) || defined(sun) || defined(__sun)
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(__APPLE__) || defined(sun) || defined(__sun) || defined(__DragonFly__)
 #define SED "gsed"
 #else
 #define SED "sed"
@@ -585,7 +585,8 @@ static char * const utils[] = {
 	"tar",
 #ifdef __APPLE__
 	"bashlock",
-#elif defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
+#elif defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) \
+	|| defined(__DragonFly__)
 	"lock",
 #elif defined __HAIKU__
 	"peaclock",
@@ -1070,7 +1071,7 @@ static char *get_cwd_entry(const char *restrict cwdpat
  */
 static void *xmemrchr(uchar_t *restrict s, uchar_t ch, size_t n)
 {
-#if defined(__GLIBC__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
+#if defined(__GLIBC__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
 	return memrchr(s, ch, n);
 #else
 
@@ -4754,7 +4755,7 @@ static bool show_stats(char *fpath)
 		("file " FILE_MIME_OPTS),
 #endif
 		"file -b",
-#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(__APPLE__)
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(__APPLE__) || defined(__DragonFly__)
 		"stat -x",
 #else
 		"stat",
@@ -5094,7 +5095,7 @@ static bool remote_mount(char *newpath)
  */
 static bool unmount(char *name, char *newpath, int *presel, char *currentpath)
 {
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__)
 	static char cmd[] = "umount";
 #else
 	static char cmd[] = "fusermount3"; /* Arch Linux utility */
@@ -5107,7 +5108,7 @@ static bool unmount(char *name, char *newpath, int *pr
 	bool hovered = FALSE;
 	char mntpath[PATH_MAX];
 
-#if !defined(__APPLE__) && !defined(__FreeBSD__)
+#if !defined(__APPLE__) && !defined(__FreeBSD__) && !defined(__DragonFly__)
 	/* On Ubuntu it's fusermount */
 	if (!found && !getutil(cmd)) {
 		cmd[10] = '\0';
@@ -5145,7 +5146,7 @@ static bool unmount(char *name, char *newpath, int *pr
 		return FALSE;
 	}
 
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__)
 	if (spawn(cmd, newpath, NULL, NULL, F_NORMAL)) {
 #else
 	if (spawn(cmd, "-qu", newpath, NULL, F_NORMAL)) {
@@ -5155,7 +5156,7 @@ static bool unmount(char *name, char *newpath, int *pr
 
 #ifdef __APPLE__
 		if (spawn(cmd, "-l", newpath, NULL, F_NORMAL)) {
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
 		if (spawn(cmd, "-f", newpath, NULL, F_NORMAL)) {
 #else
 		if (spawn(cmd, "-quz", newpath, NULL, F_NORMAL)) {
