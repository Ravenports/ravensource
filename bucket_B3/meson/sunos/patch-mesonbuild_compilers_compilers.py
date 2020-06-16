--- mesonbuild/compilers/compilers.py.orig	2020-06-14 19:40:08 UTC
+++ mesonbuild/compilers/compilers.py
@@ -368,9 +368,6 @@ def get_base_link_args(options, linker,
     # -bitcode_bundle is incompatible with -undefined and -bundle
     if bitcode and not is_shared_module:
         args.extend(linker.bitcode_args())
-    elif as_needed:
-        # -Wl,-dead_strip_dylibs is incompatible with bitcode
-        args.extend(linker.get_asneeded_args())
 
     # Apple's ld (the only one that supports bitcode) does not like -undefined
     # arguments or -headerpad_max_install_names when bitcode is enabled
@@ -608,10 +605,6 @@ class CompilerArgs(collections.abc.Mutab
                 if group_start < 0:
                     # First occurrence of a library
                     group_start = i
-            if group_start >= 0:
-                # Last occurrence of a library
-                new.insert(group_end + 1, '-Wl,--end-group')
-                new.insert(group_start, '-Wl,--start-group')
         # Remove system/default include paths added with -isystem
         if hasattr(self.compiler, 'get_default_include_dirs'):
             default_dirs = self.compiler.get_default_include_dirs()
