--- engine/SCons/Tool/__init__.py.orig	2019-01-08 02:59:06 UTC
+++ engine/SCons/Tool/__init__.py
@@ -1212,13 +1212,12 @@ def tool_list(platform, env):
         ars = ['sgiar']
     elif str(platform) == 'sunos':
         "prefer Forte tools on SunOS"
-        linkers = ['sunlink', 'gnulink']
-        c_compilers = ['suncc', 'gcc', 'cc']
-        cxx_compilers = ['suncxx', 'g++', 'cxx']
+        linkers = ['gnulink']
+        c_compilers = ['gcc', 'cc']
+        cxx_compilers = ['g++', 'cxx']
         assemblers = ['as', 'gas']
-        fortran_compilers = ['sunf95', 'sunf90', 'sunf77', 'f95', 'f90', 'f77',
-                             'gfortran', 'g77', 'fortran']
-        ars = ['sunar']
+        fortran_compilers = ['gfortran', 'g77']
+        ars = ['ar']
     elif str(platform) == 'hpux':
         "prefer aCC tools on HP-UX"
         linkers = ['hplink', 'gnulink']
