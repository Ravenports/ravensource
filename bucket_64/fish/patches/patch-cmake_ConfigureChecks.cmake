--- cmake/ConfigureChecks.cmake.orig	2022-07-20 10:15:43 UTC
+++ cmake/ConfigureChecks.cmake
@@ -203,8 +203,8 @@ int main () {
 # Check if tputs needs a function reading an int or char.
 # The only curses I can find that needs a char is OpenIndiana.
 check_cxx_source_compiles("
-#include <curses.h>
-#include <term.h>
+#include <ncurses/curses.h>
+#include <ncurses/term.h>
 
 static int writer(int b) {
     return b;
