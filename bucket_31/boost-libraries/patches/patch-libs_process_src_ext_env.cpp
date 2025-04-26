--- libs/process/src/ext/env.cpp.orig	2025-04-03 11:37:29 UTC
+++ libs/process/src/ext/env.cpp
@@ -48,6 +48,7 @@
 #include <algorithm>
 #include <cstring>
 #include <sys/types.h>
+#include <sys/sysctl.h>
 #include <kvm.h>
 #endif
 
