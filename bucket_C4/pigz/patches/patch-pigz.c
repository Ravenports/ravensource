--- pigz.c.orig	2021-01-24 05:19:13 UTC
+++ pigz.c
@@ -333,7 +333,6 @@
 // Portability defines.
 #define _FILE_OFFSET_BITS 64            // Use large file functions
 #define _LARGE_FILES                    // Same thing for AIX
-#define _POSIX_C_SOURCE 200809L         // For MinGW
 
 // Included headers and what is expected from each.
 #include <stdio.h>      // fflush(), fprintf(), fputs(), getchar(), putc(),
