--- http.c.orig	2023-08-21 17:25:20 UTC
+++ http.c
@@ -2159,7 +2159,11 @@ static int http_request_reauth(const cha
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
