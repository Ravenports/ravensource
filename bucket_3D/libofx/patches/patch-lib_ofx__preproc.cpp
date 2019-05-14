Solaris 10u8 has an older prototype

--- lib/ofx_preproc.cpp.orig	2019-02-11 22:26:59 UTC
+++ lib/ofx_preproc.cpp
@@ -306,7 +306,7 @@ int ofx_proc_file(LibofxContextPtr ctx,
             size_t outbytesleft = inbytesleft * 2 - 1;
             char * iconv_buffer = (char*) malloc (inbytesleft * 2);
             memset(iconv_buffer, 0, inbytesleft * 2);
-#if defined(__sun) || defined(__NetBSD__)
+#if defined(__NetBSD__)
             const char * inchar = (const char *)s_buffer.c_str();
 #else
             char * inchar = (char *)s_buffer.c_str();
