--- tools/install.py.orig	2023-02-16 16:14:47 UTC
+++ tools/install.py
@@ -181,7 +181,7 @@ def files(action):
   action(['deps/v8/tools/gdbinit'], 'share/doc/node/')
   action(['deps/v8/tools/lldb_commands.py'], 'share/doc/node/')
 
-  if 'freebsd' in sys.platform or 'openbsd' in sys.platform:
+  if 'skipme' in sys.platform:
     action(['doc/node.1'], 'man/man1/')
   else:
     action(['doc/node.1'], 'share/man/man1/')
