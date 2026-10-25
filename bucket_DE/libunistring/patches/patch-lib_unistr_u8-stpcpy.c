--- lib/unistr/u8-stpcpy.c.orig	2026-02-23 17:39:20 UTC
+++ lib/unistr/u8-stpcpy.c
@@ -33,7 +33,7 @@
 /* Specification.  */
 #include "unistr.h"
 
-#if HAVE_STPCPY
+#if HAVE_STPCPY && !defined(__sun__)
 
 # include <string.h>
 
