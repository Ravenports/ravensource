--- deps/cares/src/lib/ares_setup.h.orig	2024-12-10 10:44:40 UTC
+++ deps/cares/src/lib/ares_setup.h
@@ -108,9 +108,6 @@
 #  include <sys/types.h>
 #endif
 
-#ifdef HAVE_MALLOC_H
-#  include <malloc.h>
-#endif
 
 #ifdef HAVE_SYS_STAT_H
 #  include <sys/stat.h>
