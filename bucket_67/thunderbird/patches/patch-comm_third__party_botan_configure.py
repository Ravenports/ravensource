--- comm/third_party/botan/configure.py.orig	2020-07-13 18:10:04 UTC
+++ comm/third_party/botan/configure.py
@@ -2936,11 +2936,7 @@ def set_defaults_for_unset_options(optio
         options.os = find_canonical_os_name(options.os)
 
     def deduce_compiler_type_from_cc_bin(cc_bin):
-        if cc_bin.find('clang') != -1 or cc_bin in ['emcc', 'em++']:
-            return 'clang'
-        if cc_bin.find('-g++') != -1 or cc_bin.find('g++') != -1:
-            return 'gcc'
-        return None
+        return 'gcc'
 
     if options.compiler is None and options.compiler_binary is not None:
         options.compiler = deduce_compiler_type_from_cc_bin(options.compiler_binary)
