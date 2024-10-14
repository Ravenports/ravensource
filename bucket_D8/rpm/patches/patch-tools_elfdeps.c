--- tools/elfdeps.c.orig	2024-10-07 09:35:46 UTC
+++ tools/elfdeps.c
@@ -85,7 +85,7 @@ static const char *mkmarker(GElf_Ehdr *e
     if (ehdr->e_ident[EI_CLASS] == ELFCLASS64) {
 	switch (ehdr->e_machine) {
 	case EM_ALPHA:
-	case EM_FAKE_ALPHA:
+	case EM_ALPHA_STD:
 	    /* alpha doesn't traditionally have 64bit markers */
 	    break;
 	default:
