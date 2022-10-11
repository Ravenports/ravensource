--- src/corelib/tools/qsharedpointer_impl.h.orig	2022-06-24 10:42:02 UTC
+++ src/corelib/tools/qsharedpointer_impl.h
@@ -156,8 +156,6 @@ namespace QtSharedPointer {
         inline void checkQObjectShared(...) { }
         inline void setQObjectShared(...) { }
 
-        inline void operator delete(void *ptr) { ::operator delete(ptr); }
-        inline void operator delete(void *, void *) { }
     };
     // sizeof(ExternalRefCountData) = 12 (32-bit) / 16 (64-bit)
 
