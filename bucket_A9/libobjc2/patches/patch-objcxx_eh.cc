--- objcxx_eh.cc	2020-08-23 08:10:20.000000000 -0700
+++ objcxx_eh.cc.new	2023-10-13 22:07:26.543624000 -0700
@@ -16,8 +16,6 @@
 
 uint64_t cxx_exception_class;
 
-extern "C" void *__cxa_allocate_exception(size_t) noexcept;
-
 /**
  * Our own definitions of C++ ABI functions and types.  These are provided
  * because this file must not include cxxabi.h.  We need to handle subtly
