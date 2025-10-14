--- src/Missing.c.orig	2014-06-21 23:24:07.000000000 +0200
+++ src/Missing.c	2025-10-14 21:13:53.517241000 +0200
@@ -96,7 +96,7 @@
 #else
 	char* nval;
 
-	if(!name || name == '\0' || strchr(name, '=') != NULL) {
+	if(!name || *name == '\0' || strchr(name, '=') != NULL) {
 		errno = EINVAL;
 		return -1;
 	}
