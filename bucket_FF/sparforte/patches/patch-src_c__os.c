--- src/c_os.c.orig	2024-07-01 16:16:15 UTC
+++ src/c_os.c
@@ -27,7 +27,7 @@
 
 /* group_member() for BSD-based systems */
 
-#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__)
 int group_member(gid_t gid) {
   int ngroups, i, ret;
 #if defined(__APPLE__)
