--- cups/transcode.c.orig	2025-11-27 15:21:54 UTC
+++ cups/transcode.c
@@ -165,7 +165,11 @@ cupsCharsetToUTF8(
     srclen       = strlen(src);
     outBytesLeft = (size_t)maxout - 1;
 
+#if defined(__sun__)
+    iconv(map_to_utf8, (const char **)&src, &srclen, &altdestptr, &outBytesLeft);
+#else
     iconv(map_to_utf8, (char **)&src, &srclen, &altdestptr, &outBytesLeft);
+#endif
     *altdestptr = '\0';
 
     _cupsMutexUnlock(&map_mutex);
@@ -289,7 +293,11 @@ cupsUTF8ToCharset(
 
   if (map_from_utf8 != (iconv_t)-1)
   {
+#if defined(__sun__)
+    const char* altsrc = (const char*)src; 
+#else
     char *altsrc = (char *)src;		/* Silence bogus GCC type-punned */
+#endif
 
     srclen       = strlen((char *)src);
     outBytesLeft = (size_t)maxout - 1;
