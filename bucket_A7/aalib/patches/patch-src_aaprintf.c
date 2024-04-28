--- src/aaprintf.c.orig	2001-04-26 14:37:31 UTC
+++ src/aaprintf.c
@@ -7,7 +7,7 @@ int aa_printf(aa_context *c, int x, int
   char buf[1025];
   int i;
   va_start(args,fmt);
-  i=vsprintf(buf,fmt,args);
+  i=vsnprintf(buf,sizeof(buf),fmt,args);
   va_end(args);
   aa_puts(c,x,y,attr,buf);
   return i;
