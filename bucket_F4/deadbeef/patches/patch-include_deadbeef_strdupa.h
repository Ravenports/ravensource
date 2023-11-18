--- include/deadbeef/strdupa.h.orig	2023-11-07 18:15:17 UTC
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
