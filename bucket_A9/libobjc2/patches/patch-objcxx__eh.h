--- objcxx_eh.h.orig	2024-03-21 16:06:36 UTC
+++ objcxx_eh.h
@@ -14,7 +14,7 @@ extern "C" {
 #undef CXA_ALLOCATE_EXCEPTION_SPECIFIER
 #define CXA_ALLOCATE_EXCEPTION_SPECIFIER
 #endif
-void *__cxa_allocate_exception(size_t thrown_size) CXA_ALLOCATE_EXCEPTION_SPECIFIER;
+void *__cxa_allocate_exception(size_t thrown_size);
 
 /**
  * Initialises an exception object returned by __cxa_allocate_exception() for
