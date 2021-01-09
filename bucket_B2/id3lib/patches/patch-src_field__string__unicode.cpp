--- src/field_string_unicode.cpp.orig	2003-03-02 00:23:00 UTC
+++ src/field_string_unicode.cpp
@@ -27,6 +27,7 @@
 #include "field_impl.h"
 #include "id3/utils.h" // has <config.h> "id3/id3lib_streams.h" "id3/globals.h" "id3/id3lib_strings.h"
 #include "io_helpers.h"
+#include <cstring>
 
 using namespace dami;
 
