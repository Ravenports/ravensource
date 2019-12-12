--- calmwm.c.orig	2018-05-14 13:31:34 UTC
+++ calmwm.c
@@ -219,9 +219,13 @@ sighdlr(int sig)
 void
 usage(void)
 {
+#ifdef __sun__
+	(void)fprintf(stderr, "usage: cwm [-v] [-c file] [-d display]\n");
+#else
 	extern char	*__progname;
 
 	(void)fprintf(stderr, "usage: %s [-v] [-c file] [-d display]\n",
 	    __progname);
+#endif
 	exit(1);
 }
