--- src/c_os.c.orig	2020-03-28 23:21:57 UTC
+++ src/c_os.c
@@ -16,7 +16,7 @@
 #include <stdio.h>
 #include <limits.h>
 
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__)
 int group_member(gid_t gid) {
   int ngroups, i, ret;
   int groups[NGROUPS_MAX];
