--- mesonbuild/envconfig.py.orig	2023-09-29 09:27:20 UTC
+++ mesonbuild/envconfig.py
@@ -353,7 +353,7 @@ class MachineInfo(HoldableObject):
 
     def is_freebsd(self) -> bool:
         """Machine is FreeBSD?"""
-        return self.system == 'freebsd'
+        return self.system == 'freebsd' or self.system == 'midnightbsd'
 
     def is_sunos(self) -> bool:
         """Machine is illumos or Solaris?"""
