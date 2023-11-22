--- mesonbuild/envconfig.py.orig	2023-10-26 16:04:31 UTC
+++ mesonbuild/envconfig.py
@@ -352,7 +352,7 @@ class MachineInfo(HoldableObject):
 
     def is_freebsd(self) -> bool:
         """Machine is FreeBSD?"""
-        return self.system == 'freebsd'
+        return self.system == 'freebsd' or self.system == 'midnightbsd'
 
     def is_sunos(self) -> bool:
         """Machine is illumos or Solaris?"""
