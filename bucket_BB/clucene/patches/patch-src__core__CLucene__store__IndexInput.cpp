--- src/core/CLucene/store/IndexInput.cpp.orig	2011-03-17 00:21:07 UTC
+++ src/core/CLucene/store/IndexInput.cpp
@@ -41,8 +41,8 @@ CL_NS_USE(util)
   }
 
   int64_t IndexInput::readLong() {
-    int64_t i = ((int64_t)readInt() << 32);
-    return (i | ((int64_t)readInt() & 0xFFFFFFFFL));
+    uint64_t i = ((uint64_t)readInt() << 32);
+    return (i | ((uint64_t)readInt() & 0xFFFFFFFFL));
   }
 
   int64_t IndexInput::readVLong() {
