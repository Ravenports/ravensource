--- mesonbuild/compilers/compilers.py.orig	2018-11-08 22:43:05 UTC
+++ mesonbuild/compilers/compilers.py
@@ -166,7 +166,7 @@ apple_buildtype_linker_args = {'plain':
 gnulike_buildtype_linker_args = {'plain': [],
                                  'debug': [],
                                  'debugoptimized': [],
-                                 'release': ['-Wl,-O1'],
+                                 'release': [],
                                  'minsize': [],
                                  'custom': [],
                                  }
@@ -1136,19 +1136,6 @@ class Compiler:
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
@@ -1236,15 +1223,7 @@ def get_compiler_is_linuxlike(compiler):
 def get_compiler_uses_gnuld(c):
     # FIXME: Perhaps we should detect the linker in the environment?
     # FIXME: Assumes that *BSD use GNU ld, but they might start using lld soon
-    compiler_type = getattr(c, 'compiler_type', None)
-    return compiler_type in (
-        CompilerType.GCC_STANDARD,
-        CompilerType.GCC_MINGW,
-        CompilerType.GCC_CYGWIN,
-        CompilerType.CLANG_STANDARD,
-        CompilerType.CLANG_MINGW,
-        CompilerType.ICC_STANDARD,
-        CompilerType.ICC_WIN)
+    return False
 
 def get_largefile_args(compiler):
     '''
@@ -1315,8 +1294,6 @@ class GnuLikeCompiler(abc.ABC):
         self.compiler_type = compiler_type
         self.base_options = ['b_pch', 'b_lto', 'b_pgo', 'b_sanitize', 'b_coverage',
                              'b_ndebug', 'b_staticpic', 'b_asneeded']
-        if not self.compiler_type.is_osx_compiler:
-            self.base_options.append('b_lundef')
         # All GCC-like backends can do assembly
         self.can_compile_suffixes.add('s')
 
