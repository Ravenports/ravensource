--- gdb/python/python-config.py.orig	2020-09-13 02:33:41 UTC
+++ gdb/python/python-config.py
@@ -59,6 +59,8 @@ for opt in opt_flags:
 
     elif opt in ('--libs', '--ldflags'):
         libs = ['-lpython' + pyver + abiflags]
+        if getvar('LDFLAGS') is not None:
+            libs.extend(getvar('LDFLAGS').split())
         if getvar('LIBS') is not None:
             libs.extend(getvar('LIBS').split())
         if getvar('SYSLIBS') is not None:
