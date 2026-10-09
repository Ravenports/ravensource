--- http.c.orig	2026-09-28 04:30:55 UTC
+++ http.c
@@ -2452,7 +2452,11 @@ static int http_request_recoverable(cons
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
