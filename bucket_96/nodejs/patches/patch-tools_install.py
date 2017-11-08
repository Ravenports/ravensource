--- tools/install.py.orig	2017-11-07 15:08:30 UTC
+++ tools/install.py
@@ -149,7 +149,7 @@ def files(action):
   action(['deps/v8/tools/lldbinit'], 'share/doc/node/')
   action(['deps/v8/tools/lldb_commands.py'], 'share/doc/node/')
 
-  if 'freebsd' in sys.platform or 'openbsd' in sys.platform:
+  if 'skipme' in sys.platform:
     action(['doc/node.1'], 'man/man1/')
   else:
     action(['doc/node.1'], 'share/man/man1/')
