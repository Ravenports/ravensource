--- lib/localconverter.c.orig	2013-12-03 06:54:43 UTC
+++ lib/localconverter.c
@@ -599,12 +599,12 @@ localconverter_iconv_conv(idn__localconv
 	inleft = 0;
 	outbuf = NULL;
 	outleft = 0;
-	iconv(ictx, (const char **)NULL, &inleft, &outbuf, &outleft);
+	iconv(ictx, (char **)NULL, &inleft, &outbuf, &outleft);
 
 	inleft = strlen(from);
 	inbuf = from;
 	outleft = tolen - 1;	/* reserve space for terminating NUL */
-	sz = iconv(ictx, (const char **)&inbuf, &inleft, &to, &outleft);
+	sz = iconv(ictx, (char **)&inbuf, &inleft, &to, &outleft);
 
 	if (sz == (size_t)(-1) || inleft > 0) {
 		switch (errno) {
@@ -630,7 +630,7 @@ localconverter_iconv_conv(idn__localconv
 	 * Append a sequence of state reset.
 	 */
 	inleft = 0;
-	sz = iconv(ictx, (const char **)NULL, &inleft, &to, &outleft);
+	sz = iconv(ictx, (char **)NULL, &inleft, &to, &outleft);
 	if (sz == (size_t)(-1)) {
 		switch (errno) {
 		case EILSEQ: