--- ofxconnect/ofxpartner.cpp.orig	2022-04-18 20:01:27 UTC
+++ ofxconnect/ofxpartner.cpp
@@ -37,6 +37,7 @@
 #include <vector>
 #include <algorithm>
 #include <string.h>
+#include <unistd.h>
 
 using std::string;
 using std::vector;
