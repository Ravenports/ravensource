--- engine/SCons/Tool/gnulink.py.orig	2019-01-08 02:59:06 UTC
+++ engine/SCons/Tool/gnulink.py
@@ -51,7 +51,7 @@ def generate(env):
 
     # __RPATH is set to $_RPATH in the platform specification if that
     # platform supports it.
-    env['RPATHPREFIX'] = '-Wl,-rpath='
+    env['RPATHPREFIX'] = '-Wl,-rpath,'
     env['RPATHSUFFIX'] = ''
     env['_RPATH'] = '${_concat(RPATHPREFIX, RPATH, RPATHSUFFIX, __env__)}'
 
