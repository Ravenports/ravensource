--- ../../python/mozbuild/mozbuild/configure/options.py.orig	2018-12-03 23:10:15 UTC
+++ ../../python/mozbuild/mozbuild/configure/options.py
@@ -420,7 +420,11 @@ class CommandLineHelper(object):
 
     def add(self, arg, origin='command-line', args=None):
         assert origin != 'default'
-        prefix, name, values = Option.split_option(arg)
+        try:
+            prefix, name, values = Option.split_option(arg)
+        except InvalidOptionError as e:
+            print('Ignoring', arg, ':', e)
+            return
         if args is None:
             args = self._extra_args
         if args is self._extra_args and name in self._extra_args:
