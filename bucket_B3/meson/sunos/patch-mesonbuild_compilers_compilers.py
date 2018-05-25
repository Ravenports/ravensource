--- mesonbuild/compilers/compilers.py.orig	2018-05-16 16:23:56 UTC
+++ mesonbuild/compilers/compilers.py
@@ -140,7 +140,7 @@ apple_buildtype_linker_args = {'plain':
 gnulike_buildtype_linker_args = {'plain': [],
                                  'debug': [],
                                  'debugoptimized': [],
-                                 'release': ['-Wl,-O1'],
+                                 'release': [],
                                  'minsize': [],
                                  }
 
@@ -917,19 +917,6 @@ class Compiler:
             # linked against local libraries will fail to resolve them.
             args.append('-Wl,-z,origin')
         args.append('-Wl,-rpath,' + paths)
-        if get_compiler_is_linuxlike(self):
-            # Rpaths to use while linking must be absolute. These are not
-            # written to the binary. Needed only with GNU ld:
-            # https://sourceware.org/bugzilla/show_bug.cgi?id=16936
-            # Not needed on Windows or other platforms that don't use RPATH
-            # https://github.com/mesonbuild/meson/issues/1897
-            lpaths = ':'.join([os.path.join(build_dir, p) for p in rpath_paths])
-
-            # clang expands '-Wl,rpath-link,' to ['-rpath-link'] instead of ['-rpath-link','']
-            # This eats the next argument, which happens to be 'ldstdc++', causing link failures.
-            # We can dodge this problem by not adding any rpath_paths if the argument is empty.
-            if lpaths.strip() != '':
-                args += ['-Wl,-rpath-link,' + lpaths]
         return args
 
     def thread_flags(self, env):
@@ -991,10 +978,6 @@ def get_compiler_is_linuxlike(compiler):
 def get_compiler_uses_gnuld(c):
     # FIXME: Perhaps we should detect the linker in the environment?
     # FIXME: Assumes that *BSD use GNU ld, but they might start using lld soon
-    if (getattr(c, 'gcc_type', None) in (GCC_STANDARD, GCC_MINGW, GCC_CYGWIN)) or \
-       (getattr(c, 'clang_type', None) in (CLANG_STANDARD, CLANG_WIN)) or \
-       (getattr(c, 'icc_type', None) in (ICC_STANDARD, ICC_WIN)):
-        return True
     return False
 
 def get_largefile_args(compiler):
@@ -1062,8 +1045,6 @@ class GnuCompiler:
         self.defines = defines or {}
         self.base_options = ['b_pch', 'b_lto', 'b_pgo', 'b_sanitize', 'b_coverage',
                              'b_colorout', 'b_ndebug', 'b_staticpic']
-        if self.gcc_type != GCC_OSX:
-            self.base_options.append('b_lundef')
         self.base_options.append('b_asneeded')
         # All GCC backends can do assembly
         self.can_compile_suffixes.add('s')
