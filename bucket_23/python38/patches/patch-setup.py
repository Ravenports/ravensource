--- setup.py.orig	2020-07-13 12:11:53 UTC
+++ setup.py
@@ -25,7 +25,10 @@ TEST_EXTENSIONS = True
 
 # This global variable is used to hold the list of modules to be disabled.
 DISABLED_MODULE_LIST = []
-
+try:
+    DISABLED_MODULE_LIST = sysconfig.get_config_var("DISABLED_EXTENSIONS").split(" ")
+except KeyError:
+    DISABLE_MODULE_LIST = list()
 
 def get_platform():
     # Cross compiling
@@ -912,8 +915,6 @@ class PyBuildExt(build_ext):
         # use the same library for the readline and curses modules.
         if 'curses' in readline_termcap_library:
             curses_library = readline_termcap_library
-        elif self.compiler.find_library_file(self.lib_dirs, 'ncursesw'):
-            curses_library = 'ncursesw'
         # Issue 36210: OSS provided ncurses does not link on AIX
         # Use IBM supplied 'curses' for successful build of _curses
         elif AIX and self.compiler.find_library_file(self.lib_dirs, 'curses'):
@@ -983,10 +984,6 @@ class PyBuildExt(build_ext):
                 # for OS X but we need _XOPEN_SOURCE_EXTENDED here for
                 # ncurses wide char support
                 curses_defines.append(('_XOPEN_SOURCE_EXTENDED', '1'))
-        elif MACOS and curses_library == 'ncurses':
-            # Building with the system-suppied combined libncurses/libpanel
-            curses_defines.append(('HAVE_NCURSESW', '1'))
-            curses_defines.append(('_XOPEN_SOURCE_EXTENDED', '1'))
 
         curses_enabled = True
         if curses_library.startswith('ncurses'):
@@ -1472,7 +1469,7 @@ class PyBuildExt(build_ext):
             self.missing.extend(['resource', 'termios'])
 
         # Platform-specific libraries
-        if HOST_PLATFORM.startswith(('linux', 'freebsd', 'gnukfreebsd')):
+        if HOST_PLATFORM.startswith(('linux', 'dragonfly', 'freebsd', 'gnukfreebsd')):
             self.add(Extension('ossaudiodev', ['ossaudiodev.c']))
         elif not AIX:
             self.missing.append('ossaudiodev')
