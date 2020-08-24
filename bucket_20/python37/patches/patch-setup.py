--- setup.py.orig	2020-08-15 05:20:16 UTC
+++ setup.py
@@ -48,7 +48,10 @@ host_platform = get_platform()
 COMPILED_WITH_PYDEBUG = ('--with-pydebug' in sysconfig.get_config_var("CONFIG_ARGS"))
 
 # This global variable is used to hold the list of modules to be disabled.
-disabled_module_list = []
+try:
+    disabled_module_list = sysconfig.get_config_var("DISABLED_EXTENSIONS").split(" ")
+except KeyError:
+    disabled_module_list = list()
 
 def add_dir_to_list(dirlist, dir):
     """Add the directory 'dir' to the list 'dirlist' (after any relative
@@ -854,8 +857,6 @@ class PyBuildExt(build_ext):
         # use the same library for the readline and curses modules.
         if 'curses' in readline_termcap_library:
             curses_library = readline_termcap_library
-        elif self.compiler.find_library_file(lib_dirs, 'ncursesw'):
-            curses_library = 'ncursesw'
         elif self.compiler.find_library_file(lib_dirs, 'ncurses'):
             curses_library = 'ncurses'
         elif self.compiler.find_library_file(lib_dirs, 'curses'):
@@ -1400,10 +1401,6 @@ class PyBuildExt(build_ext):
                 # for OS X but we need _XOPEN_SOURCE_EXTENDED here for
                 # ncurses wide char support
                 curses_defines.append(('_XOPEN_SOURCE_EXTENDED', '1'))
-        elif host_platform == 'darwin' and curses_library == 'ncurses':
-            # Building with the system-suppied combined libncurses/libpanel
-            curses_defines.append(('HAVE_NCURSESW', '1'))
-            curses_defines.append(('_XOPEN_SOURCE_EXTENDED', '1'))
 
         if curses_library.startswith('ncurses'):
             curses_libs = [curses_library]
@@ -1625,6 +1622,10 @@ class PyBuildExt(build_ext):
             macros = dict()
             libraries = []
 
+        elif host_platform.startswith('dragonfly'):
+            macros = dict()
+            libraries = ['pthread']
+
         else:                                   # Linux and other unices
             macros = dict()
             libraries = ['rt']
@@ -1647,7 +1648,7 @@ class PyBuildExt(build_ext):
         # End multiprocessing
 
         # Platform-specific libraries
-        if host_platform.startswith(('linux', 'freebsd', 'gnukfreebsd')):
+        if host_platform.startswith(('linux', 'dragonfly', 'freebsd', 'gnukfreebsd')):
             exts.append( Extension('ossaudiodev', ['ossaudiodev.c']) )
         else:
             missing.append('ossaudiodev')
