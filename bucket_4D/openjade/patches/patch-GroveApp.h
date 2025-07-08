--- spgrove/GroveApp.h.orig	1999-05-02 12:57:37 UTC
+++ spgrove/GroveApp.h
@@ -7,9 +7,9 @@
 #pragma interface
 #endif
 
-#include "ParserApp.h"
+#include <OpenSP/ParserApp.h>
 #include "GroveBuilder.h"
-#include "HashTable.h"
+#include <OpenSP/HashTable.h>
 
 #ifdef SP_NAMESPACE
 namespace SP_NAMESPACE {
