--- src/core/CLucene/index/DocumentsWriter.cpp.orig	2011-03-17 00:21:07 UTC
+++ src/core/CLucene/index/DocumentsWriter.cpp
@@ -125,7 +125,7 @@ DocumentsWriter::~DocumentsWriter(){
   if (this->postingsFreeListDW.values){
       if (this->postingsFreeCountDW < this->postingsFreeListDW.length) {
           memset(this->postingsFreeListDW.values + this->postingsFreeCountDW
-              , NULL
+              , 0
               , sizeof(Posting*));
       }
       postingsFreeListDW.deleteUntilNULL();
