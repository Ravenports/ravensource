--- lib/onigmo/regint.h.orig	2026-11-24 16:22:45 UTC
+++ lib/onigmo/regint.h
@@ -234,7 +234,7 @@
 # define xsnprintf   sprintf_s
 # define xstrcat(dest,src,size)   strcat_s(dest,size,src)
 #else
-# define xalloca     alloca
+# define xalloca     __builtin_alloca
 # define xvsnprintf  vsnprintf
 # define xsnprintf   snprintf
 # define xstrcat(dest,src,size)	  strcat(dest,src)
