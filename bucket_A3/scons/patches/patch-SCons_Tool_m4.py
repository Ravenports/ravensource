--- SCons/Tool/m4.py.orig	2024-09-22 01:25:14 UTC
+++ SCons/Tool/m4.py
@@ -49,7 +49,7 @@ def generate(env) -> None:
     # file and run from there.
     # The src_suffix setup is like so: file.c.m4 -> file.c,
     # file.cpp.m4 -> file.cpp etc.
-    env['M4']      = 'm4'
+    env['M4']      = 'gm4'
     env['M4FLAGS'] = SCons.Util.CLVar('-E')
     env['M4COM']   = 'cd ${SOURCE.rsrcdir} && $M4 $M4FLAGS < ${SOURCE.file} > ${TARGET.abspath}'
 
