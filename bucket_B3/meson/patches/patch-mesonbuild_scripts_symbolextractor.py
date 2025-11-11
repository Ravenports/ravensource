--- mesonbuild/scripts/symbolextractor.py.orig	2025-11-10 20:43:53 UTC
+++ mesonbuild/scripts/symbolextractor.py
@@ -281,6 +281,8 @@ def gen_symbols(libfilename: str, impfil
         openbsd_syms(libfilename, outfilename)
     elif mesonlib.is_freebsd():
         freebsd_syms(libfilename, outfilename)
+    elif mesonlib.is_dragonflybsd():
+        freebsd_syms(libfilename, outfilename)
     elif mesonlib.is_netbsd():
         freebsd_syms(libfilename, outfilename)
     elif mesonlib.is_windows():
