--- http.c.orig	2025-06-16 05:11:33 UTC
+++ http.c
@@ -2283,7 +2283,11 @@ static int http_request_reauth(const cha
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
