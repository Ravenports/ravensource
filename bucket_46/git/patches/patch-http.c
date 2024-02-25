--- http.c.orig	2024-02-23 00:37:50 UTC
+++ http.c
@@ -2182,7 +2182,11 @@ static int http_request_reauth(const cha
 			return HTTP_START_FAILED;
 		}
 		rewind(result);
+#if defined(__MidnightBSD__)
+		if (ftruncate(fileno((FILE *)result), 0) < 0) {
+#else
 		if (ftruncate(fileno(result), 0) < 0) {
+#endif
 			error_errno("unable to truncate a file");
 			return HTTP_START_FAILED;
 		}
