--- src/python_interpreter/get_interpreter_metadata.py.orig	2025-06-23 14:09:29 UTC
+++ src/python_interpreter/get_interpreter_metadata.py
@@ -19,6 +19,13 @@ if platform.python_implementation() == "
 else:
     ext_suffix = sysconfig.get_config_var("EXT_SUFFIX")
 
+if platform.system() == "MidnightBSD":
+    myplatform = "freebsd-12.3-RELEASE-amd64"
+    mysystem = "freebsd"
+else:
+    myplatform = sysconfig.get_platform()
+    mysystem = platform.system().lower()
+
 metadata = {
     # sys.implementation.name can differ from platform.python_implementation(), for example
     # Pyston has sys.implementation.name == "pyston" while platform.python_implementation() == cpython
@@ -30,9 +37,9 @@ metadata = {
     "interpreter": platform.python_implementation().lower(),
     "ext_suffix": ext_suffix,
     "soabi": sysconfig.get_config_var("SOABI") or None,
-    "platform": sysconfig.get_platform(),
+    "platform": myplatform,
     # This one isn't technically necessary, but still very useful for sanity checks
-    "system": platform.system().lower(),
+    "system": mysystem,
     # This one is for generating a config file for pyo3
     "pointer_width": struct.calcsize("P") * 8,
     "gil_disabled": sysconfig.get_config_var("Py_GIL_DISABLED") == 1,
