--- nm/nm.c.orig	2026-02-17 00:39:15 UTC
+++ nm/nm.c
@@ -745,7 +745,7 @@ global_init(void)
 	if (elf_version(EV_CURRENT) == EV_NONE)
 		errx(EXIT_FAILURE, "elf_version error");
 
-	nm_info.name = ELFTC_GETPROGNAME();
+	nm_info.name = (const char *)ELFTC_GETPROGNAME();
 	nm_info.def_filename = "a.out";
 	nm_opts.print_symbol = PRINT_SYM_SYM;
 	nm_opts.print_name = PRINT_NAME_NONE;
