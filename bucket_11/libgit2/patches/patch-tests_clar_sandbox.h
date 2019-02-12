--- tests/clar/sandbox.h.orig	2019-02-02 10:25:54 UTC
+++ tests/clar/sandbox.h
@@ -125,6 +125,11 @@ static int build_sandbox_path(void)
 
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
