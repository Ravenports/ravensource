--- psutil/_psbsd.py.orig	2019-04-11 21:10:12 UTC
+++ psutil/_psbsd.py
@@ -24,6 +24,7 @@ from ._common import memoize
 from ._common import memoize_when_activated
 from ._common import NETBSD
 from ._common import OPENBSD
+from ._common import DRAGONFLY
 from ._common import sockfam_to_enum
 from ._common import socktype_to_enum
 from ._common import usage_percent
