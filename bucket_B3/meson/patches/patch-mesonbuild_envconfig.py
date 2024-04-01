--- mesonbuild/envconfig.py.orig	2024-02-26 20:51:28 UTC
+++ mesonbuild/envconfig.py
@@ -343,7 +343,7 @@ class MachineInfo(HoldableObject):
 
     def is_freebsd(self) -> bool:
         """Machine is FreeBSD?"""
-        return self.system == 'freebsd'
+        return self.system == 'freebsd' or self.system == 'midnightbsd'
 
     def is_sunos(self) -> bool:
         """Machine is illumos or Solaris?"""
