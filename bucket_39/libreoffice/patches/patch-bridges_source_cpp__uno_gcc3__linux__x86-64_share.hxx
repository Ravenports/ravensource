$NetBSD: patch-bridges_source_cpp__uno_gcc3__linux__x86-64_share.hxx,v 1.5 2019/06/27 13:50:49 ryoon Exp $

* NetBSD has no _Unwind_Exception, fix runtime crash

--- bridges/source/cpp_uno/gcc3_linux_x86-64/share.hxx.orig	2025-01-23 21:25:49 UTC
+++ bridges/source/cpp_uno/gcc3_linux_x86-64/share.hxx
@@ -101,6 +101,16 @@ public:
 // <https://mentorembedded.github.io/cxx-abi/abi-eh.html>,
 // libcxxabi/src/cxa_exception.hpp:
 namespace __cxxabiv1 {
+#if defined(__NetBSD__)
+struct _Unwind_Exception
+{
+    unsigned exception_class __attribute__((__mode__(__DI__)));
+    void * exception_cleanup;
+    unsigned private_1 __attribute__((__mode__(__word__)));
+    unsigned private_2 __attribute__((__mode__(__word__)));
+} __attribute__((__aligned__));
+#endif
+
 struct __cxa_exception {
 #if defined _LIBCPPABI_VERSION // detect libc++abi
 #if defined __LP64__ || LIBCXXABI_ARM_EHABI
