--- Src/Modules/pcre.c.orig	2018-12-16 01:39:51 UTC
+++ Src/Modules/pcre.c
@@ -183,7 +183,7 @@ zpcre_get_substrings(char *arg, int *ove
 	int nelem = arrlen(captures)-1;
 	/* Set to the offsets of the complete match */
 	if (want_offset_pair) {
-	    sprintf(offset_all, "%d %d", ovec[0], ovec[1]);
+	    sprintf(offset_all, "%zd %zd", ovec[0], ovec[1]);
 	    setsparam("ZPCRE_OP", ztrdup(offset_all));
 	}
 	/*
