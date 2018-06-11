--- psutil/__init__.py.orig	2018-05-08 16:12:59 UTC
+++ psutil/__init__.py
@@ -80,6 +80,7 @@ from ._common import FREEBSD  # NOQA
 from ._common import LINUX
 from ._common import NETBSD  # NOQA
 from ._common import OPENBSD  # NOQA
+from ._common import DRAGONFLY # NOQA
 from ._common import OSX
 from ._common import POSIX  # NOQA
 from ._common import SUNOS
@@ -200,7 +201,7 @@ __all__ = [
     "POWER_TIME_UNKNOWN", "POWER_TIME_UNLIMITED",
 
     "BSD", "FREEBSD", "LINUX", "NETBSD", "OPENBSD", "OSX", "POSIX", "SUNOS",
-    "WINDOWS", "AIX",
+    "WINDOWS", "AIX", "DRAGONFLY",
 
     # classes
     "Process", "Popen",
