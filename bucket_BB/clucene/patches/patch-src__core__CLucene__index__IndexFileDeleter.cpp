--- src/core/CLucene/index/IndexFileDeleter.cpp.orig	2011-03-17 00:21:07 UTC
+++ src/core/CLucene/index/IndexFileDeleter.cpp
@@ -129,7 +129,7 @@ IndexFileDeleter::IndexFileDeleter(Direc
 
 	  string& fileName = files.at(i);
 
-    if (filter->accept(NULL, fileName.c_str()) && !fileName.compare(IndexFileNames::SEGMENTS_GEN) == 0) {
+    if (filter->accept(NULL, fileName.c_str()) && fileName.compare(IndexFileNames::SEGMENTS_GEN) != 0) {
 
 	    // Add this file to refCounts with initial count 0:
 	    getRefCount(fileName.c_str());
