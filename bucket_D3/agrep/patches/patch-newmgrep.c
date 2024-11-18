--- newmgrep.c.orig	2016-10-22 12:40:44 UTC
+++ newmgrep.c
@@ -16,7 +16,7 @@
 #include <sys/types.h>
 #endif
 
-#if defined(_WIN32) || defined(__APPLE__)
+#if defined(_WIN32) || defined(__APPLE__) || defined(__DragonFly__) || defined(__FreeBSD__) || defined(__NetBSD__)
     #include <sys/stat.h>
 #endif
 
@@ -70,14 +70,14 @@ extern CHAR D_pattern[MaxDelimit*2];
 extern int D_length;
 extern CHAR tc_D_pattern[MaxDelimit*2];
 extern int tc_D_length;
-extern COUNT, FNAME, SILENT, FILENAMEONLY, prev_num_of_matched, num_of_matched;
-extern INVERSE, OUTTAIL;
-extern WORDBOUND, WHOLELINE, NOUPPER;
+extern int COUNT, FNAME, SILENT, FILENAMEONLY, prev_num_of_matched, num_of_matched;
+extern int INVERSE, OUTTAIL;
+extern int WORDBOUND, WHOLELINE, NOUPPER;
 extern ParseTree *AParse;
 extern int AComplexPattern;
 extern unsigned char  CurrentFileName[], Progname[]; 
-extern total_line;
-extern agrep_initialfd;
+extern int total_line;
+extern int agrep_initialfd;
 extern int EXITONERROR;
 extern int PRINTPATTERN;
 extern int agrep_inlen;
