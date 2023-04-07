--- setup.py.orig	2023-04-04 22:22:17 UTC
+++ setup.py
@@ -56,7 +56,10 @@ with warnings.catch_warnings():
 
 
 # This global variable is used to hold the list of modules to be disabled.
-DISABLED_MODULE_LIST = []
+try:
+    DISABLED_MODULE_LIST = sysconfig.get_config_var("DISABLED_EXTENSIONS").split(" ")
+except KeyError:
+    DISABLE_MODULE_LIST = []
 
 # --list-module-names option used by Tools/scripts/generate_module_names.py
 LIST_MODULE_NAMES = False
@@ -1077,8 +1080,6 @@ class PyBuildExt(build_ext):
         # use the same library for the readline and curses modules.
         if 'curses' in readline_termcap_library:
             curses_library = readline_termcap_library
-        elif self.compiler.find_library_file(self.lib_dirs, 'ncursesw'):
-            curses_library = 'ncursesw'
         # Issue 36210: OSS provided ncurses does not link on AIX
         # Use IBM supplied 'curses' for successful build of _curses
         elif AIX and self.compiler.find_library_file(self.lib_dirs, 'curses'):
@@ -1137,10 +1138,6 @@ class PyBuildExt(build_ext):
                 # for OS X but we need _XOPEN_SOURCE_EXTENDED here for
                 # ncurses wide char support
                 curses_defines.append(('_XOPEN_SOURCE_EXTENDED', '1'))
-        elif MACOS and curses_library == 'ncurses':
-            # Building with the system-suppied combined libncurses/libpanel
-            curses_defines.append(('HAVE_NCURSESW', '1'))
-            curses_defines.append(('_XOPEN_SOURCE_EXTENDED', '1'))
 
         curses_enabled = True
         if curses_library.startswith('ncurses'):
@@ -1179,7 +1176,12 @@ class PyBuildExt(build_ext):
             self.missing.append('_curses_panel')
 
     def detect_crypt(self):
-        self.addext(Extension('_crypt', ['_cryptmodule.c']))
+        if self.compiler.find_library_file(self.lib_dirs, 'crypt'):
+            libs = ['crypt']
+        else:
+            libs = []
+
+        self.addext(Extension('_crypt', ['_cryptmodule.c'], libraries=libs))
 
     def detect_dbm_gdbm(self):
         # Modules that provide persistent dictionary-like semantics.  You will
