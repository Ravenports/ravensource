--- src/tor/torlookup.c.orig	2026-04-28 10:09:20 UTC
+++ src/tor/torlookup.c
@@ -64,7 +64,7 @@ static void usage(char *name);
 
 static int traverseTree(char *const argv[]);
 
-#if defined __FreeBSD__
+#if defined __FreeBSD__ || defined __DragonFly__
 static int compare(const FTSENT *const *f1, const FTSENT *const *f2);
 #else
 static int compare(const FTSENT **f1, const FTSENT **f2);
@@ -200,7 +200,7 @@ static int processFile(char *torFile) {
     return 0;
 }  // End of processFile
 
-#if defined __FreeBSD__
+#if defined __FreeBSD__ || defined __DragonFly__
 static int compare(const FTSENT *const *f1, const FTSENT *const *f2) { return strcmp((*f1)->fts_name, (*f2)->fts_name); }  // End of compare
 #else
 static int compare(const FTSENT **f1, const FTSENT **f2) { return strcmp((*f1)->fts_name, (*f2)->fts_name); }  // End of compare
