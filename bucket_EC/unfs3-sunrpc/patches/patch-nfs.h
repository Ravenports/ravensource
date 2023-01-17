--- nfs.h.orig	2022-11-07 12:11:48 UTC
+++ nfs.h
@@ -65,6 +65,9 @@ typedef int32_t int32;
 #ifdef __APPLE__
 typedef off_t off64_t;
 #endif
+#if defined __NetBSD__ || defined __DragonFly__
+typedef off_t off64_t;
+#endif
 #endif
 
 typedef char *filename3;
