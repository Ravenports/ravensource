--- lib/gvpr/compile.c.orig	2023-09-11 18:27:30 UTC
+++ lib/gvpr/compile.c
@@ -56,7 +56,11 @@ static Sflong_t ptr2int(const void *p) {
 
 static int iofread(void *chan, char *buf, int bufsize)
 {
+#if defined(__FreeBSD__) || defined(__NetBSD__)
+  return (int)read(fileno((FILE *)chan), buf, bufsize);
+#else
   return (int)read(fileno(chan), buf, bufsize);
+#endif
 }
 
 static int ioputstr(void *chan, const char *str)
