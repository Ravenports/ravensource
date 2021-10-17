--- ext/readline/extconf.rb.org	2020-10-01 12:15:38.000000000 +0000
+++ ext/readline/extconf.rb	2021-10-17 01:17:28.347469269 +0000
@@ -33,6 +33,7 @@
 have_library("user32", nil) if /cygwin/ === RUBY_PLATFORM
 have_library("ncurses", "tgetnum") ||
   have_library("termcap", "tgetnum") ||
+  have_library("tinfo", "tgetnum") ||
   have_library("curses", "tgetnum")
 
 case enable_libedit
