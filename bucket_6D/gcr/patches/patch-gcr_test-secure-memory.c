--- gcr/test-secure-memory.c.orig	2025-02-05 11:40:17 UTC
+++ gcr/test-secure-memory.c
@@ -54,6 +54,10 @@ find_non_zero (gpointer mem, gsize len)
 static gsize
 get_rlimit_memlock (void)
 {
+#ifdef __sun__
+	g_test_skip ("test unsupported on solaris");
+	return 0;
+#else
 	struct rlimit memlock;
 
 	/* If the test program is running as a privileged user, it is
@@ -82,6 +86,7 @@ get_rlimit_memlock (void)
 	}
 
 	return memlock.rlim_cur;
+#endif
 }
 
 static void
