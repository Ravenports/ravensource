--- src/collector/expire.c.orig	2025-11-09 17:02:56 UTC
+++ src/collector/expire.c
@@ -66,7 +66,7 @@ static uint32_t timeout = 0;
 
 static void PrepareDirLists(channel_t *channel);
 
-#if defined __FreeBSD__
+#if defined __FreeBSD__ || defined __DragonFly__
 static int compare(const FTSENT *const *f1, const FTSENT *const *f2);
 #else
 static int compare(const FTSENT **f1, const FTSENT **f2);
@@ -255,7 +255,7 @@ uint64_t ParseTimeDef(char *s, uint64_t
 
 }  // End of ParseTimeDef
 
-#if defined __FreeBSD__
+#if defined __FreeBSD__ || defined __DragonFly__
 static int compare(const FTSENT *const *f1, const FTSENT *const *f2) { return strcmp((*f1)->fts_name, (*f2)->fts_name); }  // End of compare
 #else
 static int compare(const FTSENT **f1, const FTSENT **f2) { return strcmp((*f1)->fts_name, (*f2)->fts_name); }  // End of compare
