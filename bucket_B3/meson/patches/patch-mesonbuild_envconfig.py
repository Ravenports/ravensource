--- mesonbuild/envconfig.py.orig	2024-10-20 18:20:39 UTC
+++ mesonbuild/envconfig.py
@@ -344,7 +344,7 @@ class MachineInfo(HoldableObject):
 
     def is_freebsd(self) -> bool:
         """Machine is FreeBSD?"""
-        return self.system == 'freebsd'
+        return self.system == 'freebsd' or self.system == 'midnightbsd'
 
     def is_sunos(self) -> bool:
         """Machine is illumos or Solaris?"""
