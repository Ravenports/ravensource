--- src/collector/expire.c.orig	2024-10-23 17:57:56 UTC
+++ src/collector/expire.c
@@ -65,7 +65,11 @@ static uint32_t timeout = 0;
 
 static void PrepareDirLists(channel_t *channel);
 
+#if defined(__linux__)
 static int compare(const FTSENT **f1, const FTSENT **f2);
+#else
+static int compare(const FTSENT * const *f1, const FTSENT * const *f2);
+#endif
 
 static void IntHandler(int signal) {
     switch (signal) {
@@ -250,7 +254,11 @@ uint64_t ParseTimeDef(char *s, uint64_t
 
 }  // End of ParseTimeDef
 
+#if defined(__linux__)
 static int compare(const FTSENT **f1, const FTSENT **f2) { return strcmp((*f1)->fts_name, (*f2)->fts_name); }  // End of compare
+#else
+static int compare(const FTSENT * const *f1, const FTSENT * const *f2) { return strcmp((*f1)->fts_name, (*f2)->fts_name); }
+#endif
 
 void RescanDir(char *dir, dirstat_t *dirstat) {
     FTS *fts;
