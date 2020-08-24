--- Lib/distutils/unixccompiler.py.orig	2020-08-15 05:20:16 UTC
+++ Lib/distutils/unixccompiler.py
@@ -232,32 +232,7 @@ class UnixCCompiler(CCompiler):
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
-        else:
-            if self._is_gcc(compiler):
-                # gcc on non-GNU systems does not need -Wl, but can
-                # use it anyway.  Since distutils has always passed in
-                # -Wl whenever gcc was used in the past it is probably
-                # safest to keep doing so.
-                if sysconfig.get_config_var("GNULD") == "yes":
-                    # GNU ld needs an extra option to get a RUNPATH
-                    # instead of just an RPATH.
-                    return "-Wl,--enable-new-dtags,-R" + dir
-                else:
-                    return "-Wl,-R" + dir
-            else:
-                # No idea how --enable-new-dtags would be passed on to
-                # ld if this system was using GNU ld.  Don't know if a
-                # system like this even exists.
-                return "-R" + dir
+        return "-Wl,-rpath," + dir
 
     def library_option(self, lib):
         return "-l" + lib
