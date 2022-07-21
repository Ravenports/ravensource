--- utils/fstreewalk.cpp.orig	2022-06-14 12:56:23 UTC
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
