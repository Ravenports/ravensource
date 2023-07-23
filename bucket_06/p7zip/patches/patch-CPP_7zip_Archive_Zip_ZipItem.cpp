--- CPP/7zip/Archive/Zip/ZipItem.cpp.orig	2023-03-03 12:16:28 UTC
+++ CPP/7zip/Archive/Zip/ZipItem.cpp
@@ -425,7 +425,11 @@ void CItem::GetUnicodeString(UString &re
       size_t dlen = slen * 4;
       const char* dest = s_utf8.GetBuf_SetEnd(dlen + 1); // (source length * 4) + null termination
 
+#if defined(__NetBSD__) || defined(__sun)
+      size_t done = iconv(cd, (const char**)&src, &slen, (char**)&dest, &dlen);
+#else
       size_t done = iconv(cd, (char**)&src, &slen, (char**)&dest, &dlen);
+#endif
       bzero((size_t*)dest + done, 1);
 
       iconv_close(cd);
