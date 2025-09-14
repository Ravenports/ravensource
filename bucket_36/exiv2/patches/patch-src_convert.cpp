Support NetBSD and SunOS iconv being special.

--- src/convert.cpp.orig	2025-08-31 08:31:02 UTC
+++ src/convert.cpp
@@ -1431,7 +1431,11 @@ bool convertStringCharsetIconv(std::stri
     char outbuf[256];
     char* outptr = outbuf;
     size_t outbytesleft = sizeof(outbuf);
+#if (defined(__NetBSD__) && !NETBSD_POSIX_ICONV) || defined(__sun)
+    size_t rc = iconv(cd, const_cast<char **>(&inptr), &inbytesleft, &outptr, &outbytesleft);
+#else
     size_t rc = iconv(cd, &inptr, &inbytesleft, &outptr, &outbytesleft);
+#endif
     const size_t outbytesProduced = sizeof(outbuf) - outbytesleft;
     if (rc == std::numeric_limits<size_t>::max() && errno != E2BIG) {
 #ifndef SUPPRESS_WARNINGS
