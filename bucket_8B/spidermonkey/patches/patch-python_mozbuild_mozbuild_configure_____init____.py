--- ../../python/mozbuild/mozbuild/configure/__init__.py.orig	2019-05-05 01:09:41 UTC
+++ ../../python/mozbuild/mozbuild/configure/__init__.py
@@ -421,7 +421,7 @@ class ConfigureSandbox(dict):
         # All options should have been removed (handled) by now.
         for arg in self._helper:
             without_value = arg.split('=', 1)[0]
-            raise InvalidOptionError('Unknown option: %s' % without_value)
+            print('Ignoring', without_value, ': Unknown option')
 
         # Run the execution queue
         for func, args in self._execution_queue:
