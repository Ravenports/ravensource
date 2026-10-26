--- SCons/Tool/gnulink.py.orig	2026-01-23 02:53:44 UTC
+++ SCons/Tool/gnulink.py
@@ -48,7 +48,7 @@ def generate(env) -> None:
 
     # __RPATH is set to $_RPATH in the platform specification if that
     # platform supports it.
-    env['RPATHPREFIX'] = '-Wl,-rpath='
+    env['RPATHPREFIX'] = '-Wl,-rpath,'
     env['RPATHSUFFIX'] = ''
     env['_RPATH'] = '${_concat(RPATHPREFIX, RPATH, RPATHSUFFIX, __env__)}'
 
