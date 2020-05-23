--- calmwm.c.orig	2020-05-22 19:40:11 UTC
+++ calmwm.c
@@ -231,9 +231,13 @@ sighdlr(int sig)
 void
 usage(void)
 {
+#ifdef __sun__
+	(void)fprintf(stderr, "usage: cwm [-nv] [-c file] [-d display]\n");
+#else
 	extern char	*__progname;
 
 	(void)fprintf(stderr, "usage: %s [-nv] [-c file] [-d display]\n",
 	    __progname);
+#endif
 	exit(1);
 }
