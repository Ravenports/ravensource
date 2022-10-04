--- ofxconnect/ofxpartner.cpp.orig	2022-10-03 20:22:59 UTC
+++ ofxconnect/ofxpartner.cpp
@@ -37,6 +37,7 @@
 #include <vector>
 #include <algorithm>
 #include <string.h>
+#include <unistd.h>
 
 using std::string;
 using std::vector;
