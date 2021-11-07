--- extra/icu/source/common/uposixdefs.h.orig	2021-09-28 11:46:34 UTC
+++ extra/icu/source/common/uposixdefs.h
@@ -44,7 +44,9 @@
      * and define _XOPEN_SOURCE to different values depending on __STDC_VERSION__.
      * In C++ source code (e.g., putil.cpp), __STDC_VERSION__ is not defined at all.
      */
+# if !defined(__NetBSD__)
 #   define _XOPEN_SOURCE 600
+# endif
 #endif
 
 /*
