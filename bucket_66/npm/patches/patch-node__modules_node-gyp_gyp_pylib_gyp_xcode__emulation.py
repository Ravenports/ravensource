$NetBSD: patch-node__modules_node-gyp_gyp_pylib_gyp_xcode__emulation.py,v 1.1 2018/05/02 17:03:09 fhajny Exp $

Do not generate debugging symbols (uses lots of disk space).

--- node_modules/node-gyp/gyp/pylib/gyp/xcode_emulation.py.orig	2020-07-21 19:24:54 UTC
+++ node_modules/node-gyp/gyp/pylib/gyp/xcode_emulation.py
@@ -507,7 +507,7 @@ class XcodeSettings(object):
 
     self._Appendf(cflags, 'GCC_OPTIMIZATION_LEVEL', '-O%s', default='s')
 
-    if self._Test('GCC_GENERATE_DEBUGGING_SYMBOLS', 'YES', default='YES'):
+    if self._Test('GCC_GENERATE_DEBUGGING_SYMBOLS', 'YES', default='NO'):
       dbg_format = self._Settings().get('DEBUG_INFORMATION_FORMAT', 'dwarf')
       if dbg_format == 'dwarf':
         cflags.append('-gdwarf-2')
