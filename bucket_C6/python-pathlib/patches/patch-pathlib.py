--- pathlib.py.orig	2014-09-03 15:25:37 UTC
+++ pathlib.py
@@ -7,7 +7,7 @@ import posixpath
 import re
 import sys
 import time
-from collections import Sequence
+from collections.abc import Sequence
 from contextlib import contextmanager
 from errno import EINVAL, ENOENT
 from operator import attrgetter
