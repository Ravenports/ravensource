--- lib/gvpr/actions.c.orig	2023-09-11 18:27:30 UTC
+++ lib/gvpr/actions.c
@@ -33,7 +33,11 @@
 #define KINDS(p) ((AGTYPE(p) == AGRAPH) ? "graph" : (AGTYPE(p) == AGNODE) ? "node" : "edge")
 
 static int iofread(void *chan, char *buf, int bufsize) {
+#if defined(__FreeBSD__)
+  return (int)read(fileno((FILE *)chan), buf, bufsize);
+#else
   return (int)read(fileno(chan), buf, bufsize);
+#endif
 }
 
 static int ioputstr(void *chan, const char *str) {
