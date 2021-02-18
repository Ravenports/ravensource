--- include/openssl/e_os2.h.orig	2021-02-16 15:24:01 UTC
+++ include/openssl/e_os2.h
@@ -279,7 +279,9 @@ typedef unsigned __int64 uint64_t;
 #  define ossl_inline inline
 # endif
 
-# if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L
+# if (defined(__cplusplus) && __cplusplus >= 201103L)
+#  define ossl_noreturn [[noreturn]]
+# elif defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L
 #  define ossl_noreturn _Noreturn
 # elif defined(__GNUC__) && __GNUC__ >= 2
 #  define ossl_noreturn __attribute__((noreturn))
