--- cmake/ConfigureChecks.cmake.orig	2024-01-01 15:15:17 UTC
+++ cmake/ConfigureChecks.cmake
@@ -221,8 +221,8 @@ int main () {
 # Check if tputs needs a function reading an int or char.
 # The only curses I can find that needs a char is OpenIndiana.
 check_cxx_source_compiles("
-#include <curses.h>
-#include <term.h>
+#include <ncurses/curses.h>
+#include <ncurses/term.h>
 
 static int writer(int b) {
     return b;
