--- tools/elfdeps.c.orig	2024-04-08 12:58:17.867700000 +0200
+++ tools/elfdeps.c	2024-04-08 12:58:48.770872000 +0200
@@ -84,7 +84,7 @@
     if (ehdr->e_ident[EI_CLASS] == ELFCLASS64) {
 	switch (ehdr->e_machine) {
 	case EM_ALPHA:
-	case EM_FAKE_ALPHA:
+	case EM_ALPHA_STD:
 	    /* alpha doesn't traditionally have 64bit markers */
 	    break;
 	default:
