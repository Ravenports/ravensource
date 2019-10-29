--- src/chartype.h.orig	2019-10-25 20:12:05 UTC
+++ src/chartype.h
@@ -43,7 +43,6 @@
 /* In many places it is assumed that the first 127 code points are ASCII
  * compatible, so ensure wchar_t indeed does ISO 10646 and not some other
  * funky encoding that could break us in weird and wonderful ways. */
-	#error wchar_t must store ISO 10646 characters
 #endif
 #endif
 
