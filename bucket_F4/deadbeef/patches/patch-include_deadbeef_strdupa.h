--- include/deadbeef/strdupa.h.orig	2026-03-16 15:39:32 UTC
+++ include/deadbeef/strdupa.h
@@ -31,7 +31,7 @@
     ({									      \
       const char *old = (s);					      \
       size_t len = strlen (old) + 1;				      \
-      char *newstr = (char *) alloca (len);			      \
+      char *newstr = (char *) __builtin_alloca (len);			      \
       (char *) memcpy (newstr, old, len);				      \
     })
 #endif
