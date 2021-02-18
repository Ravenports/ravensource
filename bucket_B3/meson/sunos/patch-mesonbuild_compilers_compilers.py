--- mesonbuild/compilers/compilers.py.orig	2021-02-14 19:22:39 UTC
+++ mesonbuild/compilers/compilers.py
@@ -402,9 +402,6 @@ def get_base_link_args(options: 'KeyedOp
     # -bitcode_bundle is incompatible with -undefined and -bundle
     if bitcode and not is_shared_module:
         args.extend(linker.bitcode_args())
-    elif as_needed:
-        # -Wl,-dead_strip_dylibs is incompatible with bitcode
-        args.extend(linker.get_asneeded_args())
 
     # Apple's ld (the only one that supports bitcode) does not like -undefined
     # arguments or -headerpad_max_install_names when bitcode is enabled
