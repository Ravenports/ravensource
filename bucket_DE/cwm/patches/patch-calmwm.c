--- calmwm.c.orig	2020-01-04 20:45:17 UTC
+++ calmwm.c
@@ -225,9 +225,13 @@ sighdlr(int sig)
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
