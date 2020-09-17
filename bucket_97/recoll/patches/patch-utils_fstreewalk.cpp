--- utils/fstreewalk.cpp.orig	2020-09-05 07:43:16 UTC
+++ utils/fstreewalk.cpp
@@ -28,6 +28,9 @@
 #include <errno.h>
 #include <fnmatch.h>
 #include <cstring>
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#endif
 #include <algorithm>
 
 #include <sstream>
