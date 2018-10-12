--- lib/termcap/ltcap.h.orig	2009-01-04 19:32:36 UTC
+++ lib/termcap/ltcap.h
@@ -19,9 +19,7 @@
 #ifndef _LTCAP_H_
 #define _LTCAP_H_ 1
 
-#if !defined (__APPLE__)
 #  define __private_extern__
-#endif
 
 #ifndef MAX_TGETENT_BUFSIZ
 #  define MAX_TGETENT_BUFSIZ 2048
