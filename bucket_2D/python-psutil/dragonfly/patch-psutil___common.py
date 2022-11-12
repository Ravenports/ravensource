--- psutil/_common.py.orig	2022-10-21 20:20:35 UTC
+++ psutil/_common.py
@@ -49,7 +49,7 @@ _DEFAULT = object()
 __all__ = [
     # OS constants
     'FREEBSD', 'BSD', 'LINUX', 'NETBSD', 'OPENBSD', 'MACOS', 'OSX', 'POSIX',
-    'SUNOS', 'WINDOWS',
+    'SUNOS', 'WINDOWS', 'DRAGONFLY'
     # connection constants
     'CONN_CLOSE', 'CONN_CLOSE_WAIT', 'CONN_CLOSING', 'CONN_ESTABLISHED',
     'CONN_FIN_WAIT1', 'CONN_FIN_WAIT2', 'CONN_LAST_ACK', 'CONN_LISTEN',
@@ -91,7 +91,8 @@ OSX = MACOS  # deprecated alias
 FREEBSD = sys.platform.startswith(("freebsd", "midnightbsd"))
 OPENBSD = sys.platform.startswith("openbsd")
 NETBSD = sys.platform.startswith("netbsd")
-BSD = FREEBSD or OPENBSD or NETBSD
+DRAGONFLY = sys.platform.startswith("dragonfly")
+BSD = FREEBSD or OPENBSD or NETBSD or DRAGONFLY
 SUNOS = sys.platform.startswith(("sunos", "solaris"))
 AIX = sys.platform.startswith("aix")
 
