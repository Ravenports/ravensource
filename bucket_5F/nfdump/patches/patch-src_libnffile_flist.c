--- src/libnffile/flist.c.orig	2024-10-23 17:57:56 UTC
+++ src/libnffile/flist.c
@@ -235,7 +235,11 @@ static int CheckTimeWindow(char *filenam
 
 /* Functions */
 
+#if defined(__linux__) || defined(__NetBSD__)
 static int compare(const FTSENT **f1, const FTSENT **f2) { return strcmp((*f1)->fts_name, (*f2)->fts_name); }  // End of compare
+#else
+static int compare(const FTSENT * const *f1, const FTSENT * const *f2) { return strcmp((*f1)->fts_name, (*f2)->fts_name); }
+#endif
 
 static void CleanPath(char *entry) {
     char *p, *q;
