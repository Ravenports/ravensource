--- http.c.orig	2026-04-20 13:53:04 UTC
+++ http.c
@@ -2377,7 +2377,11 @@ static int http_request_recoverable(cons
 				return HTTP_START_FAILED;
 			}
 			rewind(f);
+#if defined(__MidnightBSD__)
+			if (ftruncate(fileno((FILE *)f), 0) < 0) {
+#else
 			if (ftruncate(fileno(f), 0) < 0) {
+#endif
 				error_errno("unable to truncate a file");
 				return HTTP_START_FAILED;
 			}
