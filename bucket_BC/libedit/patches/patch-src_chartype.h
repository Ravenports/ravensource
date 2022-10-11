--- src/chartype.h.orig	2022-06-11 07:57:59 UTC
+++ src/chartype.h
@@ -44,7 +44,6 @@
 /* In many places it is assumed that the first 127 code points are ASCII
  * compatible, so ensure wchar_t indeed does ISO 10646 and not some other
  * funky encoding that could break us in weird and wonderful ways. */
-	#error wchar_t must store ISO 10646 characters
 #endif
 #endif
 
