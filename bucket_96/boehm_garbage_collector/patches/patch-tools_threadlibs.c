--- tools/threadlibs.c.orig	2017-12-23 08:46:29 UTC
+++ tools/threadlibs.c
@@ -42,7 +42,7 @@ int main(void)
 #       ifdef GC_USE_DLOPEN_WRAP
           printf("-ldl ");
 #       endif
-#       if (__FREEBSD_version >= 500000)
+#       if defined __FreeBSD__ || defined __DragonFly__
           printf("-lpthread\n");
 #       else
           printf("-pthread\n");
