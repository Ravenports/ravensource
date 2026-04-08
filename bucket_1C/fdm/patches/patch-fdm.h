--- fdm.h.orig	2023-01-09 11:20:17 UTC
+++ fdm.h
@@ -38,6 +38,7 @@
 #include <signal.h>
 #include <stdarg.h>
 #include <stdint.h>
+#include <limits.h>
 #ifndef _PUBLIC_
 #define _PUBLIC_
 #endif
@@ -695,12 +696,12 @@ enum cmp {
 };
 
 /* Configuration file (used by parser). */
-struct file {
+struct fdm_file {
 	FILE		*f;
 	int		 line;
 	const char	*path;
 };
-ARRAY_DECL(files, struct file *);
+ARRAY_DECL(files, struct fdm_file *);
 
 #ifndef HAVE_SETRESUID
 #define setresuid(r, e, s) setreuid(r, e)
@@ -746,7 +747,7 @@ int			yylex(void);
 /* parse.y */
 extern struct macros	parse_macros;
 extern struct files	parse_filestack;
-extern struct file     *parse_file;
+extern struct fdm_file *parse_file;
 extern struct strb     *parse_tags;
 int			parse_conf(const char *, struct strings *);
 __dead printflike1 void yyerror(const char *, ...);
