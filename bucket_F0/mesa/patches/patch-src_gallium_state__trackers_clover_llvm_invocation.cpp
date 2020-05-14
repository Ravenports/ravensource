# fix errors like the following
#
# llvm/invocation.cpp:(.text+0x1275): undefined reference to `std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >::c_str()
 const'
# /usr/bin/ld: ../../../../src/gallium/state_trackers/clover/.libs/libclover.a(libclllvm_la-invocation.o): relocation R_X86_64_PC32 against `_ZNKSt3__112bas
ic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5c_strEv' can not be used when making a shared object; recompile with -fPIC
# /usr/bin/ld: final link failed: Bad value
#
--- src/gallium/state_trackers/clover/llvm/invocation.cpp.orig	2020-05-14 16:50:14 UTC
+++ src/gallium/state_trackers/clover/llvm/invocation.cpp
@@ -188,6 +188,8 @@ namespace {
       return get_lang_standard_from_version_str(device_version);
    }
 
+   const char* cstr(const std::string& str) { return str.c_str(); }
+
    std::unique_ptr<clang::CompilerInstance>
    create_compiler_instance(const device &dev, const std::string& ir_target,
                             const std::vector<std::string> &opts,
@@ -200,8 +202,8 @@ namespace {
       // Parse the compiler options.  A file name should be present at the end
       // and must have the .cl extension in order for the CompilerInvocation
       // class to recognize it as an OpenCL source file.
-      const std::vector<const char *> copts =
-         map(std::mem_fn(&std::string::c_str), opts);
+      std::vector<const char *> copts(opts.size());
+      std::transform(opts.begin(), opts.end(), copts.begin(), cstr);
 
       const target &target = ir_target;
       const std::string &device_clc_version = dev.device_clc_version();
