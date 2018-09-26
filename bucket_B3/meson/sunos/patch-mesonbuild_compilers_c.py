--- mesonbuild/compilers/c.py.orig	2018-08-25 08:05:50 UTC
+++ mesonbuild/compilers/c.py
@@ -163,8 +163,8 @@ class CCompiler(Compiler):
                 # Apple ld
                 return ['-Wl,-undefined,dynamic_lookup']
             else:
-                # GNU ld and LLVM lld
-                return ['-Wl,--allow-shlib-undefined']
+                # sun linker
+                return []
         elif self.id == 'msvc':
             # link.exe
             return ['/FORCE:UNRESOLVED']
