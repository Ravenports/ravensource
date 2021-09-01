--- mesonbuild/linkers/linkers.py.orig	2021-08-18 11:22:33 UTC
+++ mesonbuild/linkers/linkers.py
@@ -1260,7 +1260,12 @@ class SolarisDynamicLinker(PosixDynamicL
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
@@ -1273,13 +1278,13 @@ class SolarisDynamicLinker(PosixDynamicL
         return []
 
     def get_asneeded_args(self) -> T.List[str]:
-        return self._apply_prefix(['-z', 'ignore'])
+        return []
 
     def no_undefined_args(self) -> T.List[str]:
         return ['-z', 'defs']
 
     def get_allow_undefined_args(self) -> T.List[str]:
-        return ['-z', 'nodefs']
+        return []
 
     def fatal_warnings(self) -> T.List[str]:
         return ['-z', 'fatal-warnings']
