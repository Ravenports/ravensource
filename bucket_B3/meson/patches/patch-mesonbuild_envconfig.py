--- mesonbuild/envconfig.py.orig	2024-07-10 18:59:16 UTC
+++ mesonbuild/envconfig.py
@@ -344,7 +344,7 @@ class MachineInfo(HoldableObject):
 
     def is_freebsd(self) -> bool:
         """Machine is FreeBSD?"""
-        return self.system == 'freebsd'
+        return self.system == 'freebsd' or self.system == 'midnightbsd'
 
     def is_sunos(self) -> bool:
         """Machine is illumos or Solaris?"""
