--- psutil/__init__.py.orig	2022-05-16 12:04:03 UTC
+++ psutil/__init__.py
@@ -62,6 +62,7 @@ from ._common import NIC_DUPLEX_FULL
 from ._common import NIC_DUPLEX_HALF
 from ._common import NIC_DUPLEX_UNKNOWN
 from ._common import OPENBSD  # NOQA
+from ._common import DRAGONFLY # NOQA
 from ._common import OSX  # deprecated alias
 from ._common import POSIX  # NOQA
 from ._common import POWER_TIME_UNKNOWN
@@ -170,7 +171,7 @@ __all__ = [
     "POWER_TIME_UNKNOWN", "POWER_TIME_UNLIMITED",
 
     "BSD", "FREEBSD", "LINUX", "NETBSD", "OPENBSD", "MACOS", "OSX", "POSIX",
-    "SUNOS", "WINDOWS", "AIX",
+    "SUNOS", "WINDOWS", "AIX", "DRAGONFLY",
 
     # "RLIM_INFINITY", "RLIMIT_AS", "RLIMIT_CORE", "RLIMIT_CPU", "RLIMIT_DATA",
     # "RLIMIT_FSIZE", "RLIMIT_LOCKS", "RLIMIT_MEMLOCK", "RLIMIT_NOFILE",
