--- ofxconnect/ofxpartner.cpp.orig	2022-09-08 20:08:58 UTC
+++ ofxconnect/ofxpartner.cpp
@@ -37,6 +37,7 @@
 #include <vector>
 #include <algorithm>
 #include <string.h>
+#include <unistd.h>
 
 using std::string;
 using std::vector;
