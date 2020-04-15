--- inst/include/Rcpp/exceptions_impl.h.orig	2020-03-22 12:40:50 UTC
+++ inst/include/Rcpp/exceptions_impl.h
@@ -25,6 +25,7 @@
 #ifndef RCPP_DEMANGLER_ENABLED
 # if defined(_WIN32)     || \
     defined(__FreeBSD__) || \
+    defined(__DragonFly__) || \
     defined(__NetBSD__)  || \
     defined(__OpenBSD__) || \
     defined(__CYGWIN__)  || \
