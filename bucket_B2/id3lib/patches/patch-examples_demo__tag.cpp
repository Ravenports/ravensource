--- examples/demo_tag.cpp.orig	2003-03-02 00:23:00 UTC
+++ examples/demo_tag.cpp
@@ -16,8 +16,9 @@
 using std::cout;
 using std::endl;
 
-static const char* VERSION_NUMBER = "$Revision: 1.15 $";
+static const char* VERSION_NUMBER = "@PORTVERSION@";
 
+static
 void PrintUsage(const char *sName)
 {
   cout << "Will render both types of tag by default.  Only the last" << endl
@@ -27,6 +28,7 @@ void PrintUsage(const char *sName)
        << "render them." << endl;
 }
 
+static
 void PrintVersion(const char *sName)
 {
   cout << "Uses " << ID3LIB_FULL_NAME << endl << endl;
@@ -34,6 +36,7 @@ void PrintVersion(const char *sName)
   cout << "This program tags mp3 files with ID3v1/1.1 and/or id3v2 tags" << endl;
 }
 
+static
 void DisplayTags(ostream &os, luint nTags)
 {
   if (!((nTags & ID3TT_ID3V1) || (nTags & ID3TT_ID3V2)))
@@ -46,7 +49,7 @@ void DisplayTags(ostream &os, luint nTag
     os << "v2";
 }
 
-int main( unsigned int argc, char * const argv[])
+int main( int argc, char * const argv[])
 {
   int ulFlag = ID3TT_ID3;
   ID3D_INIT_DOUT();
