--- psutil/_psbsd.py.orig	2017-10-06 05:51:06 UTC
+++ psutil/_psbsd.py
@@ -23,6 +23,7 @@ from ._common import memoize
 from ._common import memoize_when_activated
 from ._common import NETBSD
 from ._common import OPENBSD
+from ._common import DRAGONFLY
 from ._common import sockfam_to_enum
 from ._common import socktype_to_enum
 from ._common import usage_percent
