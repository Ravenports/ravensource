--- tc.alloc.c.orig	2025-07-09 07:41:34 UTC
+++ tc.alloc.c
@@ -670,6 +670,7 @@ showall(Char **v, struct command *c)
 }
 
 #ifndef SYSMALLOC
+# ifndef __FreeBSD__
 /* jemalloc defines these */
 void _malloc_prefork(void);
 void _malloc_postfork(void);
@@ -677,4 +678,5 @@ void _malloc_postfork_child(void);
 void _malloc_prefork(void) {}
 void _malloc_postfork(void) {}
 void _malloc_postfork_child(void) {}
+# endif
 #endif
