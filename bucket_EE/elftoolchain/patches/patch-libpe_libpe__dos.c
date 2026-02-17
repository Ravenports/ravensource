--- libpe/libpe_dos.c.orig	2016-01-10 09:23:51 UTC
+++ libpe/libpe_dos.c
@@ -31,6 +31,9 @@
 #include <stdlib.h>
 #include <string.h>
 #include <unistd.h>
+#if defined(__sun__)
+#include <endian.h>
+#endif
 
 #include "_libpe.h"
 
