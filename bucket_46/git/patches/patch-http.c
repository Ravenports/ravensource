--- http.c.orig	2025-08-18 00:35:38 UTC
+++ http.c
@@ -2284,7 +2284,11 @@ static int http_request_reauth(const cha
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
