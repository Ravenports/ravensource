--- include/id3/writers.h.orig	2003-03-02 00:23:00 UTC
+++ include/id3/writers.h
@@ -30,7 +30,7 @@
 
 #include "id3/writer.h"
 #include "id3/id3lib_streams.h"
-//#include <string.h>
+#include <cstring>
 
 class ID3_CPP_EXPORT ID3_OStreamWriter : public ID3_Writer
 {
