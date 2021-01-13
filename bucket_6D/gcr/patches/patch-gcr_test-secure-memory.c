--- gcr/test-secure-memory.c.orig	2021-01-12 22:54:00 UTC
+++ gcr/test-secure-memory.c
@@ -55,6 +55,10 @@ extern int egg_secure_warnings;
 static gsize
 get_rlimit_memlock (void)
 {
+#ifdef __sun__
+	g_test_skip ("test unsupported on solaris");
+	return 0;
+#else
 	struct rlimit memlock;
 
 	/* If the test program is running as a privileged user, it is
@@ -83,6 +87,7 @@ get_rlimit_memlock (void)
 	}
 
 	return memlock.rlim_cur;
+#endif
 }
 
 static void
