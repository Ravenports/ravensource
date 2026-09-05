--- mesonbuild/linkers/linkers.py.orig	2026-09-05 18:01:49 UTC
+++ mesonbuild/linkers/linkers.py
@@ -731,7 +731,7 @@ class GnuLikeDynamicLinkerMixin(DynamicL
         return ['-pthread']
 
     def no_undefined_args(self) -> T.List[str]:
-        return self._apply_prefix('--no-undefined')
+        return []
 
     def fatal_warnings(self) -> T.List[str]:
         return self._apply_prefix('--fatal-warnings')
@@ -1604,7 +1604,13 @@ class SolarisDynamicLinker(PosixDynamicL
     def get_link_whole_for(self, args: T.List[str]) -> T.List[str]:
         if not args:
             return args
-        return self._apply_prefix('--whole-archive') + args + self._apply_prefix('--no-whole-archive')
+        return (
+            self._apply_prefix('-z') +
+            self._apply_prefix('allextract') +
+            args +
+            self._apply_prefix('-z') +
+            self._apply_prefix('defaultextract')
+        )
 
     def get_pie_args(self) -> T.List[str]:
         # Available in Solaris 11.2 and later
