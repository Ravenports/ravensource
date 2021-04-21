--- plugin/xlib/vimdot.sh.orig	2021-04-17 19:19:13 UTC
+++ plugin/xlib/vimdot.sh
@@ -10,7 +10,7 @@ error() { echo "$0: $*" >&2; exit 1; }
 
 # Try $EDITOR first, else try vim or vi
 editor="$EDITOR"
-[ -x "$editor" ] || editor="/usr/bin/vim"
+[ -x "$editor" ] || editor="/usr/local/bin/vim"
 [ -x "$editor" ] || editor="/usr/bin/vi"
 [ -x "$editor" ] || error "EDITOR not found or not executable";
 
@@ -30,7 +30,7 @@ digraph G {
 
 	vim [href="http://www.vim.org/"]
 	dot [href="http://www.graphviz.org/"]
-	vimdot [href="file:///usr/bin/vimdot"]
+	vimdot [href="file:///usr/local/bin/vimdot"]
 
 	{vim dot} -> vimdot
 }
