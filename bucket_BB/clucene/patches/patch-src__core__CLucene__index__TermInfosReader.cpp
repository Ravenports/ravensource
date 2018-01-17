--- src/core/CLucene/index/TermInfosReader.cpp.orig	2011-03-17 00:21:07 UTC
+++ src/core/CLucene/index/TermInfosReader.cpp
@@ -111,7 +111,7 @@ CL_NS_DEF(index)
 	      //destroy their elements
 #ifdef _DEBUG
          for ( int32_t i=0; i<indexTermsLength;++i ){
-            indexTerms[i].__cl_refcount--;
+            indexTerms[i].__cl_decref();
          }
 #endif
          //Delete the arrays
