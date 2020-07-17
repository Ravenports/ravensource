--- psutil/_psbsd.py.orig	2020-06-20 15:55:24 UTC
+++ psutil/_psbsd.py
@@ -25,6 +25,7 @@ from ._common import memoize_when_activa
 from ._common import NETBSD
 from ._common import NoSuchProcess
 from ._common import OPENBSD
+from ._common import DRAGONFLY
 from ._common import usage_percent
 from ._common import ZombieProcess
 from ._compat import FileNotFoundError
