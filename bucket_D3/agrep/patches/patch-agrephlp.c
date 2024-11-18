--- agrephlp.c.orig	2016-10-22 12:40:44 UTC
+++ agrephlp.c
@@ -65,8 +65,8 @@ int get_current_codepage();  /* codepage
 #include "agrep.h"
 #include "version.h"
 
-extern	AGREPOPT_STR[MAX_LINE_LEN];
-extern	VERBOSE;
+extern	int AGREPOPT_STR[MAX_LINE_LEN];
+extern	int VERBOSE;
 
 #ifdef __EMX__
 extern	unsigned int _emx_env;
