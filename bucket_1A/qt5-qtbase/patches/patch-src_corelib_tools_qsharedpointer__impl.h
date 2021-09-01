--- src/corelib/tools/qsharedpointer_impl.h.orig	2020-10-27 08:02:11 UTC
+++ src/corelib/tools/qsharedpointer_impl.h
@@ -156,8 +156,6 @@ namespace QtSharedPointer {
         inline void checkQObjectShared(...) { }
         inline void setQObjectShared(...) { }
 
-        inline void operator delete(void *ptr) { ::operator delete(ptr); }
-        inline void operator delete(void *, void *) { }
     };
     // sizeof(ExternalRefCountData) = 12 (32-bit) / 16 (64-bit)
 
