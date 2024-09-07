--- giscanner/ccompiler.py.orig	2024-04-01 13:21:25 UTC
+++ giscanner/ccompiler.py
@@ -26,7 +26,6 @@ import tempfile
 import sys
 import distutils
 
-from distutils.msvccompiler import MSVCCompiler
 from distutils.unixccompiler import UnixCCompiler
 from distutils.cygwinccompiler import Mingw32CCompiler
 from distutils.sysconfig import get_config_vars
@@ -232,7 +231,7 @@ class CCompiler(object):
 
                 # Ensure libraries are always linked as we are going to use ldd to work
                 # out their names later
-                if sys.platform != 'darwin':
+                if sys.platform != 'darwin' and sys.platform != 'sunos5':
                     args.append('-Wl,--no-as-needed')
 
         for library_path in libpaths:
@@ -460,7 +459,7 @@ class CCompiler(object):
             return self.compiler.linker_exe
 
     def check_is_msvc(self):
-        return isinstance(self.compiler, MSVCCompiler)
+        return False
 
     # Private APIs
     def _set_cpp_options(self, options):
@@ -486,8 +485,6 @@ class CCompiler(object):
                     # macros for compiling using distutils
                     # get dropped for MSVC builds, so
                     # escape the escape character.
-                    if isinstance(self.compiler, MSVCCompiler):
-                        macro_value = macro_value.replace('\"', '\\\"')
                 macros.append((macro_name, macro_value))
             elif option.startswith('-U'):
                 macros.append((option[len('-U'):],))
