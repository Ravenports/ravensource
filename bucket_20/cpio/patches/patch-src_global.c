--- src/global.c.orig	2019-11-03 15:07:23 UTC
+++ src/global.c
@@ -184,9 +184,6 @@ unsigned int warn_option = 0;
 /* Extract to standard output? */
 bool to_stdout_option = false;
 
-/* The name this program was run with.  */
-char *program_name;
-
 /* A pointer to either lstat or stat, depending on whether
    dereferencing of symlinks is done for input files.  */
 int (*xstat) ();
