--- salt/utils/msgpack.py.orig	2020-06-16 17:48:56.676387000 +0200
+++ salt/utils/msgpack.py	2020-06-16 17:51:42.199540000 +0200
@@ -68,13 +68,27 @@
 
     return kwargs
 
+def _sanitize_msgpack_unpack_kwargs(kwargs):
+    """
+    Clean up msgpack keyword arguments for unpack operations, based on
+    the version
+    https://github.com/msgpack/msgpack-python/blob/master/ChangeLog.rst
+    """
+    assert isinstance(kwargs, dict)
+    if version >= (1, 0, 0) and kwargs.get("raw", None) is None:
+        log.info("adding `raw=True` argument to msgpack call")
+        kwargs["raw"] = True
+
+    return _sanitize_msgpack_kwargs(kwargs)
 
 class Unpacker(msgpack.Unpacker):
     '''
     Wraps the msgpack.Unpacker and removes non-relevant arguments
     '''
     def __init__(self, *args, **kwargs):
-        msgpack.Unpacker.__init__(self, *args, **_sanitize_msgpack_kwargs(kwargs))
+            msgpack.Unpacker.__init__(
+            self, *args, **_sanitize_msgpack_unpack_kwargs(kwargs)
+        )
 
 
 def pack(o, stream, **kwargs):
@@ -113,7 +127,7 @@
     By default, this function uses the msgpack module and falls back to
     msgpack_pure, if the msgpack is not available.
     '''
-    return msgpack.unpack(stream, **_sanitize_msgpack_kwargs(kwargs))
+    return msgpack.unpack(stream, **_sanitize_msgpack_unpack_kwargs(kwargs))
 
 
 def unpackb(packed, **kwargs):
@@ -125,7 +139,7 @@
     By default, this function uses the msgpack module and falls back to
     msgpack_pure.
     '''
-    return msgpack.unpackb(packed, **_sanitize_msgpack_kwargs(kwargs))
+    return msgpack.unpackb(packed, **_sanitize_msgpack_unpack_kwargs(kwargs))
 
 
 # alias for compatibility to simplejson/marshal/pickle.
