--- mesonbuild/compilers/compilers.py.orig	2018-12-09 14:27:23 UTC
+++ mesonbuild/compilers/compilers.py
@@ -177,7 +177,7 @@ apple_buildtype_linker_args = {'plain':
 gnulike_buildtype_linker_args = {'plain': [],
                                  'debug': [],
                                  'debugoptimized': [],
-                                 'release': ['-Wl,-O1'],
+                                 'release': [],
                                  'minsize': [],
                                  'custom': [],
                                  }
@@ -1210,19 +1210,6 @@ class Compiler:
                     paths = paths + ':' + padding
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
@@ -1354,15 +1341,7 @@ def get_compiler_is_linuxlike(compiler):
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
@@ -1433,8 +1412,6 @@ class GnuLikeCompiler(abc.ABC):
         self.compiler_type = compiler_type
         self.base_options = ['b_pch', 'b_lto', 'b_pgo', 'b_sanitize', 'b_coverage',
                              'b_ndebug', 'b_staticpic', 'b_pie']
-        if not self.compiler_type.is_osx_compiler and not self.compiler_type.is_windows_compiler:
-            self.base_options.append('b_lundef')
         if not self.compiler_type.is_windows_compiler:
             self.base_options.append('b_asneeded')
         # All GCC-like backends can do assembly
@@ -1542,8 +1519,8 @@ class GnuLikeCompiler(abc.ABC):
             # For PE/COFF this is impossible
             return []
         else:
-            # GNU ld and LLVM lld
-            return ['-Wl,--allow-shlib-undefined']
+            # sun linker
+            return []
 
 
 class GnuCompiler(GnuLikeCompiler):
