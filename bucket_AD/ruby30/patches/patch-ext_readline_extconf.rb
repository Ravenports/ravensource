--- ext/readline/extconf.rb.orig	2021-07-07 10:08:35 UTC
+++ ext/readline/extconf.rb
@@ -33,6 +33,7 @@ enable_libedit = enable_config("libedit"
 have_library("user32", nil) if /cygwin/ === RUBY_PLATFORM
 have_library("ncurses", "tgetnum") ||
   have_library("termcap", "tgetnum") ||
+  have_library("tinfo", "tgetnum") ||
   have_library("curses", "tgetnum")
 
 case enable_libedit
