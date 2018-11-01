--- psutil/__init__.py.orig	2018-10-28 14:03:53 UTC
+++ psutil/__init__.py
@@ -81,6 +81,7 @@ from ._common import LINUX
 from ._common import MACOS
 from ._common import NETBSD  # NOQA
 from ._common import OPENBSD  # NOQA
+from ._common import DRAGONFLY # NOQA
 from ._common import OSX  # deprecated alias
 from ._common import POSIX  # NOQA
 from ._common import SUNOS
@@ -202,7 +203,7 @@ __all__ = [
     "POWER_TIME_UNKNOWN", "POWER_TIME_UNLIMITED",
 
     "BSD", "FREEBSD", "LINUX", "NETBSD", "OPENBSD", "MACOS", "OSX", "POSIX",
-    "SUNOS", "WINDOWS", "AIX",
+    "SUNOS", "WINDOWS", "AIX", "DRAGONFLY",
 
     # classes
     "Process", "Popen",
