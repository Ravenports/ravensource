--- mesonbuild/linkers.py.orig	2019-09-28 23:52:33 UTC
+++ mesonbuild/linkers.py
@@ -876,9 +876,7 @@ class SolarisDynamicLinker(PosixDynamicL
     """Sys-V derived linker used on Solaris and OpenSolaris."""
 
     def get_link_whole_for(self, args: typing.List[str]) -> typing.List[str]:
-        if not args:
-            return args
-        return self._apply_prefix('--whole-archive') + args + self._apply_prefix('--no-whole-archive')
+        return args
 
     def no_undefined_args(self) -> typing.List[str]:
         return ['-z', 'defs']
