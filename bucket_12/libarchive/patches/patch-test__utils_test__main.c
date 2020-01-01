--- test_utils/test_main.c.orig	2019-12-30 01:39:54 UTC
+++ test_utils/test_main.c
@@ -3499,9 +3499,9 @@ static int
 test_run(int i, const char *tmpdir)
 {
 #ifdef PATH_MAX
-	char workdir[PATH_MAX];
+	char workdir[PATH_MAX+1];
 #else
-	char workdir[1024];
+	char workdir[1024+1];
 #endif
 	char logfilename[64];
 	int failures_before = failures;
