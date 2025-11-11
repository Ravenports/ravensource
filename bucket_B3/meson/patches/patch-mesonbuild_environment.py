--- mesonbuild/environment.py.orig	2025-11-10 20:57:42 UTC
+++ mesonbuild/environment.py
@@ -386,6 +386,8 @@ def detect_cpu_family(compilers: Compile
         trial = detect_windows_arch(compilers)
     elif mesonlib.is_freebsd() or mesonlib.is_netbsd() or mesonlib.is_openbsd() or mesonlib.is_qnx() or mesonlib.is_aix():
         trial = platform.processor().lower()
+    elif mesonlib.is_dragonflybsd():
+        trial = platform.processor().lower()
     else:
         trial = platform.machine().lower()
     if trial.startswith('i') and trial.endswith('86'):
@@ -452,6 +454,8 @@ def detect_cpu(compilers: CompilersDict)
         trial = detect_windows_arch(compilers)
     elif mesonlib.is_freebsd() or mesonlib.is_netbsd() or mesonlib.is_openbsd() or mesonlib.is_aix():
         trial = platform.processor().lower()
+    elif mesonlib.is_dragonflybsd():
+        trial = platform.processor().lower()
     else:
         trial = platform.machine().lower()
 
