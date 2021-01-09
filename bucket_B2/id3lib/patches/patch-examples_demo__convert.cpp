--- examples/demo_convert.cpp.orig	2003-03-02 00:23:00 UTC
+++ examples/demo_convert.cpp
@@ -24,8 +24,9 @@
 using std::cout;
 using std::endl;
 
-static const char* VERSION_NUMBER = "$Revision: 1.15 $";
+static const char* VERSION_NUMBER = "@PORTVERSION@";
 
+static
 void PrintUsage(const char *sName)
 {
   cout << "Converts between id3v1 and id3v2 tags of an mp3 file." << endl;
@@ -37,6 +38,7 @@ void PrintUsage(const char *sName)
        << "render them." << endl;
 }
 
+static
 void PrintVersion(const char *sName)
 {
   size_t nIndex;
@@ -64,6 +66,7 @@ void PrintVersion(const char *sName)
   cout << "tags to ID3v2 tags." << endl << endl;
 }
 
+static
 void DisplayTags(ostream &os, luint nTags)
 {
   if (!((nTags & ID3TT_ID3V1) || (nTags & ID3TT_ID3V2)))
@@ -84,7 +87,7 @@ void DisplayTags(ostream &os, luint nTag
   }
 }
 
-int main( unsigned int argc, char * const argv[])
+int main( int argc, char * const argv[])
 {
   flags_t ulFlag = ID3TT_ALL;
   gengetopt_args_info args;
