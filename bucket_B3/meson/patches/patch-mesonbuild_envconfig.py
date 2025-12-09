--- mesonbuild/envconfig.py.orig	2025-12-09 16:59:30 UTC
+++ mesonbuild/envconfig.py
@@ -360,7 +360,7 @@ class MachineInfo(HoldableObject):
 
     def is_freebsd(self) -> bool:
         """Machine is FreeBSD?"""
-        return self.system == 'freebsd'
+        return self.system == 'freebsd' or self.system == 'midnightbsd'
 
     def is_sunos(self) -> bool:
         """Machine is illumos or Solaris?"""
@@ -579,6 +579,8 @@ def detect_cpu_family(compilers: T.Dict[
         trial = detect_windows_arch(compilers)
     elif mesonlib.is_freebsd() or mesonlib.is_netbsd() or mesonlib.is_openbsd() or mesonlib.is_qnx() or mesonlib.is_aix():
         trial = platform.processor().lower()
+    elif mesonlib.is_dragonflybsd():
+        trial = platform.processor().lower()
     else:
         trial = platform.machine().lower()
     if trial.startswith('i') and trial.endswith('86'):
@@ -645,6 +647,8 @@ def detect_cpu(compilers: T.Dict[str, Co
         trial = detect_windows_arch(compilers)
     elif mesonlib.is_freebsd() or mesonlib.is_netbsd() or mesonlib.is_openbsd() or mesonlib.is_aix():
         trial = platform.processor().lower()
+    elif mesonlib.is_dragonflybsd():
+        trial = platform.processor().lower()
     else:
         trial = platform.machine().lower()
 
