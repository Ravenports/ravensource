Add missing TLS keyword - __thread (clang/gcc extension)

To unbreak scanner on headers like <sys/errno.h> and <runetype.h>:
/usr/include/runetype.h:94: syntax error, unexpected '{', expecting ',' or ';' in '{' at '{

--- giscanner/scannerlexer.l.orig	2025-09-13 11:08:06 UTC
+++ giscanner/scannerlexer.l
@@ -180,6 +180,7 @@ stringtext				([^\\\"])|(\\.)
 "__pragma" 		                { if (!parse_ignored_macro()) REJECT; }
 "__restrict"				{ return RESTRICT; }
 "__restrict__"				{ return RESTRICT; }
+"__thread"				{ return THREAD_LOCAL; }
 "thread_local"				{ return THREAD_LOCAL; }
 "_Thread_local"				{ return THREAD_LOCAL; }
 "__typeof__"				{ if (parse_ignored_macro()) return VOID; else REJECT; }
