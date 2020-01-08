--- mesonbuild/linkers.py.orig	2019-12-29 22:47:27 UTC
+++ mesonbuild/linkers.py
@@ -870,7 +870,12 @@ class SolarisDynamicLinker(PosixDynamicL
     def get_link_whole_for(self, args: typing.List[str]) -> typing.List[str]:
         if not args:
             return args
-        return self._apply_prefix('--whole-archive') + args + self._apply_prefix('--no-whole-archive')
+        result = [self.prefix_arg + '-z', self.prefix_arg + 'allextract']
+        for a in args:
+            result.append(a)
+        result.append(self.prefix_arg + '-z')
+        result.append(self.prefix_arg + 'defaultextract')
+        return result
 
     def no_undefined_args(self) -> typing.List[str]:
         return ['-z', 'defs']
