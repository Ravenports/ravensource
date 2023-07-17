--- mesonbuild/envconfig.py.orig	2023-06-28 14:48:20 UTC
+++ mesonbuild/envconfig.py
@@ -351,7 +351,7 @@ class MachineInfo(HoldableObject):
 
     def is_freebsd(self) -> bool:
         """Machine is FreeBSD?"""
-        return self.system == 'freebsd'
+        return self.system == 'freebsd' or self.system == 'midnightbsd'
 
     def is_sunos(self) -> bool:
         """Machine is illumos or Solaris?"""
