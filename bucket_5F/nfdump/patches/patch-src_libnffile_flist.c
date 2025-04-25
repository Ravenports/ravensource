--- src/libnffile/flist.c.orig	2025-04-18 13:29:25 UTC
+++ src/libnffile/flist.c
@@ -236,7 +236,7 @@ static int CheckTimeWindow(char *filenam
 
 /* Functions */
 
-#if defined __FreeBSD__
+#if defined __FreeBSD__ || defined __DragonFly__
 static int compare(const FTSENT *const *f1, const FTSENT *const *f2) { return strcmp((*f1)->fts_name, (*f2)->fts_name); }  // End of compare
 #else
 static int compare(const FTSENT **f1, const FTSENT **f2) { return strcmp((*f1)->fts_name, (*f2)->fts_name); }  // End of compare
