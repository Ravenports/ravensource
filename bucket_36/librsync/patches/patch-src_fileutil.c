--- src/fileutil.c.orig	2023-02-19 05:08:08 UTC
+++ src/fileutil.c
@@ -75,7 +75,9 @@
 
 /* Use and prefer _fileno if it exists. */
 #ifdef HAVE__FILENO
+# if !defined(__NetBSD__)
 #  define fileno(f) _fileno((f))
+# endif
 #endif
 
 FILE *rs_file_open(char const *filename, char const *mode, int force)
