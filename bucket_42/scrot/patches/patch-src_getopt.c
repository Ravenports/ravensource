--- src/getopt.c.orig	2019-07-09 23:53:19 UTC
+++ src/getopt.c
@@ -39,6 +39,7 @@
 #endif
 #endif
 
+#include <string.h>
 #include <stdio.h>
 
 /* Comment out all this code if we are using the GNU C Library, and are not
@@ -691,7 +692,7 @@ _getopt_internal(argc, argv, optstring,
                optarg = nameend + 1;
             else
             {
-               if (opterr)
+               if (opterr) {
                   if (argv[optind - 1][1] == '-')
                      /* --option */
                      fprintf(stderr,
@@ -704,6 +705,7 @@ _getopt_internal(argc, argv, optstring,
                              _
                              ("%s: option `%c%s' doesn't allow an argument\n"),
                              argv[0], argv[optind - 1][0], pfound->name);
+               }
 
                nextchar += strlen(nextchar);
 
