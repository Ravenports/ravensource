--- examples/heif_convert.cc.orig	2020-09-25 08:28:40 UTC
+++ examples/heif_convert.cc
@@ -30,7 +30,11 @@
 #if defined(_MSC_VER) || defined(__MINGW32__)
 # include <malloc.h>
 #else
+# if defined(__DragonFly__) || defined(__FreeBSD__)
+# include <stdlib.h>
+# else
 # include <alloca.h>
+# endif
 #endif
 
 #include <cstring>
