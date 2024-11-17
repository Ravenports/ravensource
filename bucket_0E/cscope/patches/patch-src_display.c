--- src/display.c.orig	2018-07-19 19:45:17 UTC
+++ src/display.c
@@ -57,9 +57,9 @@
 #include <stdarg.h>
 
 #ifndef HAVE_SIGSETJMP
-# define sigsetjmp(a,b) setjmp(a)
-# define siglongjmp(a,b) longjmp(a,b)
-typedef jmp_buf sigjmp_buf;
+//# define sigsetjmp(a,b) setjmp(a)
+//# define siglongjmp(a,b) longjmp(a,b)
+//typedef jmp_buf sigjmp_buf;
 #endif
 
 int	booklen;		/* OGS book name display field length */
