$NetBSD: patch-bridges_source_cpp__uno_gcc3__linux__intel_share.hxx,v 1.2 2019/06/27 13:50:49 ryoon Exp $

* NetBSD has no _Unwind_Exception, fix runtime crash

--- bridges/source/cpp_uno/gcc3_linux_intel/share.hxx.orig	2025-06-05 10:22:59 UTC
+++ bridges/source/cpp_uno/gcc3_linux_intel/share.hxx
@@ -62,6 +62,15 @@ public:
 
 namespace CPPU_CURRENT_NAMESPACE
 {
+#if defined(__NetBSD__)
+struct _Unwind_Exception
+{
+    unsigned exception_class __attribute__((__mode__(__DI__)));
+    void * exception_cleanup;
+    unsigned private_1 __attribute__((__mode__(__word__)));
+    unsigned private_2 __attribute__((__mode__(__word__)));
+} __attribute__((__aligned__));
+#endif
 
 void dummy_can_throw_anything( char const * );
 
