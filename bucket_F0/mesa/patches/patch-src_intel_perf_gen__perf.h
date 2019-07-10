--- src/intel/perf/gen_perf.h.orig	2019-07-09 09:10:45 UTC
+++ src/intel/perf/gen_perf.h
@@ -28,7 +28,9 @@
 #include <stdint.h>
 #include <string.h>
 
+#ifdef __linux__
 #include <sys/sysmacros.h>
+#endif
 
 #include "util/hash_table.h"
 #include "util/ralloc.h"
