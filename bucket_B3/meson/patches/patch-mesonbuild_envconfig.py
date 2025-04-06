--- mesonbuild/envconfig.py.orig	2025-04-06 19:57:59 UTC
+++ mesonbuild/envconfig.py
@@ -345,7 +345,7 @@ class MachineInfo(HoldableObject):
 
     def is_freebsd(self) -> bool:
         """Machine is FreeBSD?"""
-        return self.system == 'freebsd'
+        return self.system == 'freebsd' or self.system == 'midnightbsd'
 
     def is_sunos(self) -> bool:
         """Machine is illumos or Solaris?"""
