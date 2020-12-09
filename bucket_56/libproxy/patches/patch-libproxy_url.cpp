--- libproxy/url.cpp.orig	2020-12-04 11:07:46 UTC
+++ libproxy/url.cpp
@@ -25,6 +25,7 @@
 #include <cstring> // For memcpy()
 #include <sstream> // For int/string conversion (using stringstream)
 #include <cstdio>  // For sscanf()
+#include <cerrno>
 #include <cstdlib>    // For atoi()
 #include <sys/stat.h> // For stat()
 #include <algorithm> // For transform()
