--- mesonbuild/envconfig.py.orig	2026-08-21 01:29:42 UTC
+++ mesonbuild/envconfig.py
@@ -379,7 +379,7 @@ class MachineInfo(HoldableObject):
 
     def is_freebsd(self) -> bool:
         """Machine is FreeBSD?"""
-        return self.system == 'freebsd'
+        return self.system == 'freebsd' or self.system == 'midnightbsd'
 
     def is_sunos(self) -> bool:
         """Machine is illumos or Solaris?"""
@@ -602,6 +602,8 @@ def detect_cpu_family(compilers: Compile
         trial = detect_windows_arch(compilers)
     elif mesonlib.is_freebsd() or mesonlib.is_netbsd() or mesonlib.is_openbsd() or mesonlib.is_qnx() or mesonlib.is_aix():
         trial = platform.processor().lower()
+    elif mesonlib.is_dragonflybsd():
+        trial = platform.processor().lower()
     else:
         trial = platform.machine().lower()
     if trial.startswith('i') and trial.endswith('86'):
@@ -668,6 +670,8 @@ def detect_cpu(compilers: CompilerDict)
         trial = detect_windows_arch(compilers)
     elif mesonlib.is_freebsd() or mesonlib.is_netbsd() or mesonlib.is_openbsd() or mesonlib.is_aix():
         trial = platform.processor().lower()
+    elif mesonlib.is_dragonflybsd():
+        trial = platform.processor().lower()
     else:
         trial = platform.machine().lower()
 
