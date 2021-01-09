--- examples/demo_copy.cpp.orig	2003-03-02 00:23:00 UTC
+++ examples/demo_copy.cpp
@@ -26,8 +26,9 @@ using std::cout;
 using std::endl;
 using std::cerr;
 
-static const char* VERSION_NUMBER = "$Revision: 1.11 $";
+static const char* VERSION_NUMBER = "@PORTVERSION@";
 
+static
 void PrintUsage(const char *sName)
 {
   cout << "Usage: " << sName << " [OPTION]... SOURCE DEST" << endl;
@@ -35,6 +36,7 @@ void PrintUsage(const char *sName)
   cout << endl;
 }
 
+static
 void PrintVersion(const char *sName)
 {
   size_t nIndex;
@@ -61,6 +63,7 @@ void PrintVersion(const char *sName)
   cout << "This program copies tags from one file to another" << endl;
 }
 
+static
 void DisplayTags(ostream &os, luint nTags)
 {
   if (!((nTags & ID3TT_ID3V1) || (nTags & ID3TT_ID3V2)))
@@ -81,7 +84,7 @@ void DisplayTags(ostream &os, luint nTag
   }
 }
 
-int main( unsigned int argc, char * const argv[])
+int main( int argc, char * const argv[])
 {
   int ulFlag = ID3TT_ID3;
   ID3D_INIT_DOUT();
