--- Lib/distutils/unixccompiler.py.orig	2020-04-19 21:13:39 UTC
+++ Lib/distutils/unixccompiler.py
@@ -227,21 +227,7 @@ class UnixCCompiler(CCompiler):
         # the configuration data stored in the Python installation, so
         # we use this hack.
         compiler = os.path.basename(sysconfig.get_config_var("CC"))
-        if sys.platform[:6] == "darwin":
-            # MacOSX's linker doesn't understand the -R flag at all
-            return "-L" + dir
-        elif sys.platform[:7] == "freebsd":
-            return "-Wl,-rpath=" + dir
-        elif sys.platform[:5] == "hp-ux":
-            if self._is_gcc(compiler):
-                return ["-Wl,+s", "-L" + dir]
-            return ["+s", "-L" + dir]
-        elif sys.platform[:7] == "irix646" or sys.platform[:6] == "osf1V5":
-            return ["-rpath", dir]
-        elif self._is_gcc(compiler):
-            return "-Wl,-R" + dir
-        else:
-            return "-R" + dir
+        return "-Wl,-rpath," + dir
 
     def library_option(self, lib):
         return "-l" + lib
