--- codepage.c.orig	2016-10-22 12:40:44 UTC
+++ codepage.c
@@ -47,7 +47,7 @@ char	CP_MAPPING;			/* -i option = case(i
 unsigned char LUT[256];			/* THE LOOK-UP TABLE (filled in AGREP.C) */
 
 
-int get_current_codepage(VOID)
+int get_current_codepage(int VOID)
 
 #ifdef __EMX__
 
