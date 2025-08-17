Change msgpack version check to include the latest in Ravenports
Ref: issue 367

--- src/borg/helpers/msgpack.py.orig	2025-04-18 19:16:24 UTC
+++ src/borg/helpers/msgpack.py
@@ -137,7 +137,7 @@ def is_slow_msgpack():
 def is_supported_msgpack():
     # DO NOT CHANGE OR REMOVE! See also requirements and comments in pyproject.toml.
     import msgpack
-    return (1, 0, 3) <= msgpack.version <= (1, 1, 0) and \
+    return (1, 0, 3) <= msgpack.version <= (1, 1, 1) and \
            msgpack.version not in []  # < add bad releases here to deny list
 
 
