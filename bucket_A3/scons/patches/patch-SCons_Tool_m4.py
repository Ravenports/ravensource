--- SCons/Tool/m4.py.orig	2026-01-23 02:53:44 UTC
+++ SCons/Tool/m4.py
@@ -48,7 +48,7 @@ def generate(env) -> None:
     # file and run from there.
     # The src_suffix setup is like so: file.c.m4 -> file.c,
     # file.cpp.m4 -> file.cpp etc.
-    env['M4']      = 'm4'
+    env['M4']      = 'gm4'
     env['M4FLAGS'] = SCons.Util.CLVar('-E')
     env['M4COM']   = 'cd ${SOURCE.rsrcdir} && $M4 $M4FLAGS < ${SOURCE.file} > ${TARGET.abspath}'
 
