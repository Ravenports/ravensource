--- mesonbuild/envconfig.py.orig	2025-08-24 17:28:31 UTC
+++ mesonbuild/envconfig.py
@@ -354,7 +354,7 @@ class MachineInfo(HoldableObject):
 
     def is_freebsd(self) -> bool:
         """Machine is FreeBSD?"""
-        return self.system == 'freebsd'
+        return self.system == 'freebsd' or self.system == 'midnightbsd'
 
     def is_sunos(self) -> bool:
         """Machine is illumos or Solaris?"""
