--- gold/stringpool.cc.orig	2024-08-16 23:00:00 UTC
+++ gold/stringpool.cc
@@ -25,7 +25,9 @@
 #include <cstring>
 #include <algorithm>
 #include <vector>
+#if !defined(__NetBSD__)
 #include <uchar.h>
+#endif
 
 #include "output.h"
 #include "parameters.h"
