X-Git-Url: https://sourceware.org/git/?p=binutils-gdb.git;a=blobdiff_plain;f=gdb%2Fcompleter.c;h=a51c16ac7f8ffce28cca7d9a4220f2d940c9f626;hp=d3900ae201443ab0a5510816e9c5589ef36b9f5b;hb=1add37b567a7dee39d99f37b37802034c3fce9c4;hpb=692e92c5af88ae509d81e484d270dd6072a41ff2

--- gdb/completer.c.orig
+++ gdb/completer.c
@@ -36,7 +36,7 @@
    calling a hook instead so we eliminate the CLI dependency.  */
 #include "gdbcmd.h"
 
-/* Needed for rl_completer_word_break_characters() and for
+/* Needed for rl_completer_word_break_characters and for
    rl_filename_completion_function.  */
 #include "readline/readline.h"
 
@@ -2011,7 +2011,7 @@ gdb_completion_word_break_characters_throw ()
       rl_basic_quote_characters = NULL;
     }
 
-  return rl_completer_word_break_characters;
+  return (char *) rl_completer_word_break_characters;
 }
 
 char *
