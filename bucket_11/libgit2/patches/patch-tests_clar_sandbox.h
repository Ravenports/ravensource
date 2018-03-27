--- tests/clar/sandbox.h.orig	2018-03-23 14:38:34 UTC
+++ tests/clar/sandbox.h
@@ -113,6 +113,11 @@ static int build_sandbox_path(void)
 
 	if (mkdir(_clar_path, 0700) != 0)
 		return -1;
+#elif defined __sun__
+	if (mktemp(_clar_path) == NULL)
+		return -1;
+	if (mkdir(_clar_path, 0700) != 0)
+		return -1;
 #else
 	if (mkdtemp(_clar_path) == NULL)
 		return -1;
