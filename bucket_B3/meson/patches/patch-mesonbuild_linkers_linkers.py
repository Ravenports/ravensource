--- mesonbuild/linkers/linkers.py.orig	2024-12-16 20:34:40 UTC
+++ mesonbuild/linkers/linkers.py
@@ -649,7 +649,7 @@ class GnuLikeDynamicLinkerMixin(DynamicL
         return ['-pthread']
 
     def no_undefined_args(self) -> T.List[str]:
-        return self._apply_prefix('--no-undefined')
+        return []
 
     def fatal_warnings(self) -> T.List[str]:
         return self._apply_prefix('--fatal-warnings')
@@ -1425,7 +1425,12 @@ class SolarisDynamicLinker(PosixDynamicL
     def get_link_whole_for(self, args: T.List[str]) -> T.List[str]:
         if not args:
             return args
-        return self._apply_prefix('--whole-archive') + args + self._apply_prefix('--no-whole-archive')
+        result = [self.prefix_arg + '-z', self.prefix_arg + 'allextract']
+        for a in args:
+            result.append(a)
+        result.append(self.prefix_arg + '-z')
+        result.append(self.prefix_arg + 'defaultextract')
+        return result
 
     def get_pie_args(self) -> T.List[str]:
         # Available in Solaris 11.2 and later
