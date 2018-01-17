--- src/core/CLucene/store/FSDirectory.cpp.orig	2011-03-17 00:21:07 UTC
+++ src/core/CLucene/store/FSDirectory.cpp
@@ -219,9 +219,8 @@ CL_NS_USE(util)
 		_CLDECDELETE(handle);
 
 		//printf("handle=%d\n", handle->__cl_refcount);
-		if ( dounlock ){
-			mutex->unlock();
-		}else{
+		mutex->unlock();
+		if ( !dounlock ) {
 			delete mutex;
 		}
 	}
