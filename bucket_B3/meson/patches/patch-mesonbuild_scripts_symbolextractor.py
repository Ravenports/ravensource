--- mesonbuild/scripts/symbolextractor.py.orig	2025-11-10 20:43:53 UTC
+++ mesonbuild/scripts/symbolextractor.py
@@ -165,18 +165,22 @@ def freebsd_syms(libfilename: str, outfi
     # Get the name of the library
     output = call_tool('readelf', ['-d', libfilename])
     if not output:
+        mlog.warning('readelf command failed')
         dummy_syms(outfilename)
         return
     result = [x for x in output.split('\n') if 'SONAME' in x]
+    mlog.warning('result= ' + '\n'.join(result) + '\n')
     assert len(result) <= 1
     # Get a list of all symbols exported
     output = call_tool('nm', ['--dynamic', '--extern-only', '--defined-only',
                               '--format=posix', libfilename])
     if not output:
+        mlog.warning('nm command failed')
         dummy_syms(outfilename)
         return
 
     result += [' '.join(x.split()[0:2]) for x in output.split('\n')]
+    mlog.warning('\n'.join(result) + '\n')
     write_if_changed('\n'.join(result) + '\n', outfilename)
 
 def cygwin_syms(impfilename: str, outfilename: str) -> None:
@@ -281,6 +285,8 @@ def gen_symbols(libfilename: str, impfil
         openbsd_syms(libfilename, outfilename)
     elif mesonlib.is_freebsd():
         freebsd_syms(libfilename, outfilename)
+    elif mesonlib.is_dragonflybsd():
+        freebsd_syms(libfilename, outfilename)
     elif mesonlib.is_netbsd():
         freebsd_syms(libfilename, outfilename)
     elif mesonlib.is_windows():
