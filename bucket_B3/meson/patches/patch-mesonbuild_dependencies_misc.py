--- mesonbuild/dependencies/misc.py.orig	2018-08-25 08:05:43 UTC
+++ mesonbuild/dependencies/misc.py
@@ -315,17 +315,6 @@ class Python3Dependency(ExternalDependen
         if not self.is_found:
             if mesonlib.is_windows() and DependencyMethods.SYSCONFIG in self.methods:
                 self._find_libpy3_windows(environment)
-            elif mesonlib.is_osx() and DependencyMethods.EXTRAFRAMEWORK in self.methods:
-                # In OSX the Python 3 framework does not have a version
-                # number in its name.
-                # There is a python in /System/Library/Frameworks, but that's
-                # python 2, Python 3 will always bin in /Library
-                fw = ExtraFrameworkDependency(
-                    'python', False, '/Library/Frameworks', self.env, self.language, kwargs)
-                if fw.found():
-                    self.compile_args = fw.get_compile_args()
-                    self.link_args = fw.get_link_args()
-                    self.is_found = True
         if self.is_found:
             mlog.log('Dependency', mlog.bold(self.name), 'found:', mlog.green('YES'))
         else:
