--- src/c_os.c.orig	2022-04-22 02:27:33 UTC
+++ src/c_os.c
@@ -16,7 +16,7 @@
 #include <stdio.h>
 #include <limits.h>
 
-#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__)
 int group_member(gid_t gid) {
   int ngroups, i, ret;
 #if defined(__APPLE__)
