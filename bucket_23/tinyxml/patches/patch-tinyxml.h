--- tinyxml.h.orig	2011-05-15 02:24:57 UTC
+++ tinyxml.h
@@ -26,6 +26,8 @@ distribution.
 #ifndef TINYXML_INCLUDED
 #define TINYXML_INCLUDED
 
+#define TIXML_USE_STL
+
 #ifdef _MSC_VER
 #pragma warning( push )
 #pragma warning( disable : 4530 )
