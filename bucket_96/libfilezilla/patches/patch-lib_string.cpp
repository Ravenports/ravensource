--- lib/string.cpp.orig	2025-03-26 10:07:26 UTC
+++ lib/string.cpp
@@ -16,6 +16,11 @@
 
 #include <cstdlib>
 
+#if defined(__sun__)
+#include <cwchar>
+using std::wcsnrtombs;
+#endif
+
 static_assert('a' + 25 == 'z', "We only support systems running with an ASCII-based character set. Sorry, no EBCDIC.");
 
 // char may be unsigned, yielding stange results if subtracting characters. To work around it, expect a particular order of characters.
