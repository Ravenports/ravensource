--- build/rpmfc.c.orig	2024-10-07 09:35:46 UTC
+++ build/rpmfc.c
@@ -295,7 +295,12 @@ static int getOutputFrom(ARGV_t argv,
 	return -1;
     }
     
+#if defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__)
+    sig_t oldhandler;
+    oldhandler = signal(SIGPIPE, SIG_IGN);
+#else
     sighandler_t oldhandler = signal(SIGPIPE, SIG_IGN);
+#endif
 
     child = fork();
     if (child < 0) {
