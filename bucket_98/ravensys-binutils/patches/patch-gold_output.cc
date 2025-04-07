--- gold/output.cc.orig	2024-08-16 23:00:00 UTC
+++ gold/output.cc
@@ -29,7 +29,9 @@
 #include <unistd.h>
 #include <sys/stat.h>
 #include <algorithm>
+#if !defined(__NetBSD__)
 #include <uchar.h>
+#endif
 
 #ifdef HAVE_SYS_MMAN_H
 #include <sys/mman.h>
