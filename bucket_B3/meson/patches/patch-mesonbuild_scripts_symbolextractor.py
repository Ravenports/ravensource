--- mesonbuild/scripts/symbolextractor.py.orig	2026-08-21 01:29:42 UTC
+++ mesonbuild/scripts/symbolextractor.py
@@ -302,6 +302,8 @@ def gen_symbols(libfilename: str, impfil
         openbsd_syms(libfilename, outfilename)
     elif mesonlib.is_freebsd():
         freebsd_syms(libfilename, outfilename)
+    elif mesonlib.is_dragonflybsd():
+        freebsd_syms(libfilename, outfilename)
     elif mesonlib.is_netbsd():
         freebsd_syms(libfilename, outfilename)
     elif mesonlib.is_windows():
