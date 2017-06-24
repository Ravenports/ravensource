--- libpkg/elfhints.c.orig	2017-03-09 12:57:56 UTC
+++ libpkg/elfhints.c
@@ -305,6 +305,10 @@ shlib_list_from_elf_hints(const char *hi
 #if defined __FreeBSD__ || defined __DragonFly__
 	read_elf_hints(hintsfile, 1);
 #endif
+#if defined __linux__
+	add_dir ("fake-elf-hints-1", "/lib/x86_64-linux-gnu", 1);
+	add_dir ("fake-elf-hints-2", "/usr/lib/x86_64-linux-gnu", 1);
+#endif
 
 	return (scan_dirs_for_shlibs(&shlibs, ndirs, dirs, true));
 }
