--- cmake/ConfigureChecks.cmake.orig	2023-01-07 14:12:25 UTC
+++ cmake/ConfigureChecks.cmake
@@ -215,8 +215,8 @@ int main () {
 # Check if tputs needs a function reading an int or char.
 # The only curses I can find that needs a char is OpenIndiana.
 check_cxx_source_compiles("
-#include <curses.h>
-#include <term.h>
+#include <ncurses/curses.h>
+#include <ncurses/term.h>
 
 static int writer(int b) {
     return b;
