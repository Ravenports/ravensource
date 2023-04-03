--- mesonbuild/envconfig.py.orig	2023-02-20 12:58:43 UTC
+++ mesonbuild/envconfig.py
@@ -339,7 +339,7 @@ class MachineInfo(HoldableObject):
 
     def is_freebsd(self) -> bool:
         """Machine is FreeBSD?"""
-        return self.system == 'freebsd'
+        return self.system == 'freebsd' or self.system == 'midnightbsd'
 
     def is_sunos(self) -> bool:
         """Machine is illumos or Solaris?"""
