--- src/jrd/common.h.orig	2018-01-05 09:38:19 UTC
+++ src/jrd/common.h
@@ -339,9 +339,6 @@ your operating system.
 Earlier versions of Solaris still have the problem. pbeach Feb2010
 */
 
-#if (!defined(__arch64__)) && (!defined(SFIO))
-#error "need to use SFIO"
-#endif
 
 // this function is normally defined in stdio.h, but is missing in SFIO's h-file
 extern "C" int remove(const char* path);
