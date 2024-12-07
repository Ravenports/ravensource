--- plugin/xlib/vimdot.sh.orig	2024-12-06 23:53:25 UTC
+++ plugin/xlib/vimdot.sh
@@ -9,8 +9,8 @@ fi
 error() { echo "$0: $*" >&2; exit 1; }
 
 # Try $EDITOR first, else try vim or vi
-editor="$(which $EDITOR)" || editor="/usr/bin/vim"
-[ -x "$editor" ] || editor="/usr/bin/vi"
+editor="$(which $EDITOR)" || editor="%%LOCALBASE%%/bin/vim"
+[ -x "$editor" ] || editor="%%LOCALBASE%%/bin/vi"
 [ -x "$editor" ] || error "EDITOR not found or not executable";
 
 default="noname.gv"
@@ -29,7 +29,7 @@ digraph G {
 
 	vim [href="http://www.vim.org/"]
 	dot [href="http://www.graphviz.org/"]
-	vimdot [href="file:///usr/bin/vimdot"]
+	vimdot [href="file:///%%LOCALBASE%%/bin/vimdot"]
 
 	{vim dot} -> vimdot
 }
