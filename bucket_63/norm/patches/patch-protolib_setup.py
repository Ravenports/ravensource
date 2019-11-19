--- protolib/setup.py.orig	2019-11-11 14:54:17 UTC
+++ protolib/setup.py
@@ -23,7 +23,7 @@ system = platform.system().lower()
 sys_macros = [('HAVE_ASSERT',None), ('HAVE_IPV6',None), ('PROTO_DEBUG', None)]
 sys_libs = ['protokit']
 
-if system in ('linux', 'darwin', 'freebsd'):
+if system in ('linux', 'darwin', 'freebsd', 'dragonfly'):
     sys_macros.append(('UNIX',None))
 elif system in ('windows'):
     sys_macros.append(('WIN32',None))
