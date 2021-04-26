--- ofxconnect/ofxpartner.cpp.orig	2021-04-23 20:35:57 UTC
+++ ofxconnect/ofxpartner.cpp
@@ -37,6 +37,7 @@
 #include <vector>
 #include <algorithm>
 #include <string.h>
+#include <unistd.h>
 
 using std::string;
 using std::vector;
