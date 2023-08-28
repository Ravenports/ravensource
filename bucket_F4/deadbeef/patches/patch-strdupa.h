--- strdupa.h.orig	2023-02-19 17:12:18 UTC
+++ strdupa.h
@@ -31,7 +31,7 @@
     ({									      \
       const char *old = (s);					      \
       size_t len = strlen (old) + 1;				      \
-      char *newstr = (char *) alloca (len);			      \
+      char *newstr = (char *) __builtin_alloca (len);			      \
       (char *) memcpy (newstr, old, len);				      \
     })
 #endif
