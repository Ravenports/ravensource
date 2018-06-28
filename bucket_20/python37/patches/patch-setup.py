--- setup.py.orig	2018-06-27 03:07:35 UTC
+++ setup.py
@@ -43,7 +43,10 @@ host_platform = get_platform()
 COMPILED_WITH_PYDEBUG = ('--with-pydebug' in sysconfig.get_config_var("CONFIG_ARGS"))
 
 # This global variable is used to hold the list of modules to be disabled.
-disabled_module_list = []
+try:
+    disabled_module_list = sysconfig.get_config_var("DISABLED_EXTENSIONS").split(" ")
+except KeyError:
+    disabled_module_list = list()
 
 def add_dir_to_list(dirlist, dir):
     """Add the directory 'dir' to the list 'dirlist' (after any relative
@@ -1581,6 +1584,10 @@ class PyBuildExt(build_ext):
             macros = dict()
             libraries = []
 
+        elif host_platform.startswith('dragonfly'):
+            macros = dict()
+            libraries = ['pthread']
+
         else:                                   # Linux and other unices
             macros = dict()
             libraries = ['rt']
@@ -1603,7 +1610,7 @@ class PyBuildExt(build_ext):
         # End multiprocessing
 
         # Platform-specific libraries
-        if host_platform.startswith(('linux', 'freebsd', 'gnukfreebsd')):
+        if host_platform.startswith(('linux', 'dragonfly', 'freebsd', 'gnukfreebsd')):
             exts.append( Extension('ossaudiodev', ['ossaudiodev.c']) )
         else:
             missing.append('ossaudiodev')
