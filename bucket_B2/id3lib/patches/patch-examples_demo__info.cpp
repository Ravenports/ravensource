--- examples/demo_info.cpp.orig	2003-03-02 00:23:00 UTC
+++ examples/demo_info.cpp
@@ -33,8 +33,9 @@ using namespace dami;
 using std::cout;
 using std::endl;
 
-static String VERSION_NUMBER = "$Revision: 1.32 $";
+static String VERSION_NUMBER = "@PORTVERSION@";
 
+static
 void PrintUsage(const char *sName)
 {
   cout << "Usage: " << sName << " [OPTION]... [FILE]..." << endl;
@@ -46,6 +47,7 @@ void PrintUsage(const char *sName)
   cout << "Will not differentiate between the two types of tags" << endl;
 }
 
+static
 void PrintVersion(const char *sName)
 {
   cout << sName << " " << VERSION_NUMBER.c_str() << endl;
@@ -53,6 +55,7 @@ void PrintVersion(const char *sName)
   cout << "Uses " << ID3LIB_FULL_NAME << endl << endl;
 }
 
+static
 void PrintInformation(const ID3_Tag &myTag)
 {
   ID3_Tag::ConstIterator* iter = myTag.CreateIterator();
@@ -309,7 +312,7 @@ void PrintInformation(const ID3_Tag &myT
 
 #define DEBUG
 
-int main( unsigned int argc, char * const argv[])
+int main( int argc, char * const argv[])
 {
   ID3D_INIT_DOUT();
 
