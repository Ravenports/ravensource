--- utils/fstreewalk.cpp.orig	2024-09-02 15:46:49 UTC
+++ utils/fstreewalk.cpp
@@ -22,6 +22,9 @@
 #include <errno.h>
 #include <fnmatch.h>
 #include <cstring>
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#endif
 #include <algorithm>
 #include <sstream>
 #include <vector>
