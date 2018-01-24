--- mesonbuild/compilers/compilers.py.orig	2017-12-06 13:50:57 UTC
+++ mesonbuild/compilers/compilers.py
@@ -130,7 +130,7 @@ apple_buildtype_linker_args = {'plain':
 gnulike_buildtype_linker_args = {'plain': [],
                                  'debug': [],
                                  'debugoptimized': [],
-                                 'release': ['-Wl,-O1'],
+                                 'release': [],
                                  'minsize': [],
                                  }
 
@@ -853,14 +853,6 @@ class Compiler:
             else:
                 paths = paths + ':' + padding
         args = ['-Wl,-rpath,' + paths]
-        if get_compiler_is_linuxlike(self):
-            # Rpaths to use while linking must be absolute. These are not
-            # written to the binary. Needed only with GNU ld:
-            # https://sourceware.org/bugzilla/show_bug.cgi?id=16936
-            # Not needed on Windows or other platforms that don't use RPATH
-            # https://github.com/mesonbuild/meson/issues/1897
-            lpaths = ':'.join([os.path.join(build_dir, p) for p in rpath_paths])
-            args += ['-Wl,-rpath-link,' + lpaths]
         return args
 
 
@@ -907,10 +899,6 @@ def get_compiler_is_linuxlike(compiler):
 def get_compiler_uses_gnuld(c):
     # FIXME: Perhaps we should detect the linker in the environment?
     # FIXME: Assumes that *BSD use GNU ld, but they might start using lld soon
-    if (getattr(c, 'gcc_type', None) in (GCC_STANDARD, GCC_MINGW, GCC_CYGWIN)) or \
-       (getattr(c, 'clang_type', None) in (CLANG_STANDARD, CLANG_WIN)) or \
-       (getattr(c, 'icc_type', None) in (ICC_STANDARD, ICC_WIN)):
-        return True
     return False
 
 def get_largefile_args(compiler):
@@ -978,9 +966,6 @@ class GnuCompiler:
         self.defines = defines or {}
         self.base_options = ['b_pch', 'b_lto', 'b_pgo', 'b_sanitize', 'b_coverage',
                              'b_colorout', 'b_ndebug', 'b_staticpic']
-        if self.gcc_type != GCC_OSX:
-            self.base_options.append('b_lundef')
-            self.base_options.append('b_asneeded')
         # All GCC backends can do assembly
         self.can_compile_suffixes.add('s')
 
