Solaris 10u8 has an older prototype

--- lib/ofx_preproc.cpp.orig	2021-01-02 23:33:04 UTC
+++ lib/ofx_preproc.cpp
@@ -307,7 +307,7 @@ int ofx_proc_file(LibofxContextPtr ctx,
             size_t outbytesleft = inbytesleft * 2 - 1;
             char * iconv_buffer = (char*) malloc (inbytesleft * 2);
             memset(iconv_buffer, 0, inbytesleft * 2);
-#if defined(__WIN32__) || defined(__sun) || defined(__NetBSD__)
+#if defined(__WIN32__) || defined(__NetBSD__)
             const char * inchar = (const char *)s_buffer.c_str();
 #else
             char * inchar = (char *)s_buffer.c_str();
