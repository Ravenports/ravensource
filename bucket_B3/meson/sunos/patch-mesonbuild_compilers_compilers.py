--- mesonbuild/compilers/compilers.py.orig	2019-06-16 18:54:18 UTC
+++ mesonbuild/compilers/compilers.py
@@ -201,7 +201,7 @@ apple_buildtype_linker_args = {'plain':
 gnulike_buildtype_linker_args = {'plain': [],
                                  'debug': [],
                                  'debugoptimized': [],
-                                 'release': ['-Wl,-O1'],
+                                 'release': [],
                                  'minsize': [],
                                  'custom': [],
                                  }
@@ -559,9 +559,6 @@ def get_base_link_args(options, linker,
     # -bitcode_bundle is incompatible with -undefined and -bundle
     if bitcode and not is_shared_module:
         args.append('-Wl,-bitcode_bundle')
-    elif as_needed:
-        # -Wl,-dead_strip_dylibs is incompatible with bitcode
-        args.append(linker.get_asneeded_args())
     try:
         crt_val = options['b_vscrt'].value
         buildtype = options['buildtype'].value
@@ -1304,25 +1301,6 @@ class Compiler:
         if mesonlib.is_sunos():
             return args
 
-        if get_compiler_is_linuxlike(self):
-            # Rpaths to use while linking must be absolute. These are not
-            # written to the binary. Needed only with GNU ld:
-            # https://sourceware.org/bugzilla/show_bug.cgi?id=16936
-            # Not needed on Windows or other platforms that don't use RPATH
-            # https://github.com/mesonbuild/meson/issues/1897
-            #
-            # In addition, this linker option tends to be quite long and some
-            # compilers have trouble dealing with it. That's why we will include
-            # one option per folder, like this:
-            #
-            #   -Wl,-rpath-link,/path/to/folder1 -Wl,-rpath,/path/to/folder2 ...
-            #
-            # ...instead of just one single looooong option, like this:
-            #
-            #   -Wl,-rpath-link,/path/to/folder1:/path/to/folder2:...
-
-            args += ['-Wl,-rpath-link,' + os.path.join(build_dir, p) for p in rpath_paths]
-
         return args
 
     def thread_flags(self, env):
@@ -1458,15 +1436,7 @@ def get_compiler_is_linuxlike(compiler):
 def get_compiler_uses_gnuld(c):
     # FIXME: Perhaps we should detect the linker in the environment?
     # FIXME: Assumes that *BSD use GNU ld, but they might start using lld soon
-    compiler_type = getattr(c, 'compiler_type', None)
-    return compiler_type in {
-        CompilerType.GCC_STANDARD,
-        CompilerType.GCC_MINGW,
-        CompilerType.GCC_CYGWIN,
-        CompilerType.CLANG_STANDARD,
-        CompilerType.CLANG_MINGW,
-        CompilerType.ICC_STANDARD,
-    }
+    return False
 
 def get_largefile_args(compiler):
     '''
@@ -1869,10 +1839,6 @@ class GnuLikeCompiler(abc.ABC):
         self.compiler_type = compiler_type
         self.base_options = ['b_pch', 'b_lto', 'b_pgo', 'b_sanitize', 'b_coverage',
                              'b_ndebug', 'b_staticpic', 'b_pie']
-        if (not self.compiler_type.is_osx_compiler and
-                not self.compiler_type.is_windows_compiler and
-                not mesonlib.is_openbsd()):
-            self.base_options.append('b_lundef')
         if not self.compiler_type.is_windows_compiler:
             self.base_options.append('b_asneeded')
         # All GCC-like backends can do assembly
@@ -1982,8 +1948,8 @@ class GnuLikeCompiler(abc.ABC):
         elif mesonlib.is_sunos():
             return []
         else:
-            # GNU ld and LLVM lld
-            return ['-Wl,--allow-shlib-undefined']
+            # sun linker
+            return []
 
     def get_gui_app_args(self, value):
         if self.compiler_type.is_windows_compiler:
