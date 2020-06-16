--- tests/unit/utils/test_msgpack.py.orig	2020-05-13 20:58:34.000000000 +0200
+++ tests/unit/utils/test_msgpack.py	2020-06-16 17:52:29.680014000 +0200
@@ -184,6 +184,75 @@
         msgpack_util_items = set(dir(salt.utils.msgpack))
         self.assertFalse(msgpack_items - msgpack_util_items, 'msgpack functions with no alias in `salt.utils.msgpack`')
 
+    def test_sanitize_msgpack_kwargs(self):
+        """
+        Test helper function _sanitize_msgpack_kwargs
+        """
+        version = salt.utils.msgpack.version
+
+        kwargs = {"strict_map_key": True, "raw": True, "use_bin_type": True}
+        salt.utils.msgpack.version = (0, 6, 0)
+        self.assertEqual(
+            salt.utils.msgpack._sanitize_msgpack_kwargs(kwargs),
+            {"raw": True, "strict_map_key": True, "use_bin_type": True},
+        )
+
+        kwargs = {"strict_map_key": True, "raw": True, "use_bin_type": True}
+        salt.utils.msgpack.version = (0, 5, 2)
+        self.assertEqual(
+            salt.utils.msgpack._sanitize_msgpack_kwargs(kwargs),
+            {"raw": True, "use_bin_type": True},
+        )
+
+        kwargs = {"strict_map_key": True, "raw": True, "use_bin_type": True}
+        salt.utils.msgpack.version = (0, 4, 0)
+        self.assertEqual(
+            salt.utils.msgpack._sanitize_msgpack_kwargs(kwargs), {"use_bin_type": True}
+        )
+
+        kwargs = {"strict_map_key": True, "raw": True, "use_bin_type": True}
+        salt.utils.msgpack.version = (0, 3, 0)
+        self.assertEqual(salt.utils.msgpack._sanitize_msgpack_kwargs(kwargs), {})
+        salt.utils.msgpack.version = version
+
+    def test_sanitize_msgpack_unpack_kwargs(self):
+        """
+        Test helper function _sanitize_msgpack_unpack_kwargs
+        """
+        version = salt.utils.msgpack.version
+
+        kwargs = {"strict_map_key": True, "use_bin_type": True}
+        salt.utils.msgpack.version = (1, 0, 0)
+        self.assertEqual(
+            salt.utils.msgpack._sanitize_msgpack_unpack_kwargs(kwargs),
+            {"raw": True, "strict_map_key": True, "use_bin_type": True},
+        )
+
+        kwargs = {"strict_map_key": True, "use_bin_type": True}
+        salt.utils.msgpack.version = (0, 6, 0)
+        self.assertEqual(
+            salt.utils.msgpack._sanitize_msgpack_unpack_kwargs(kwargs),
+            {"strict_map_key": True, "use_bin_type": True},
+        )
+
+        kwargs = {"strict_map_key": True, "use_bin_type": True}
+        salt.utils.msgpack.version = (0, 5, 2)
+        self.assertEqual(
+            salt.utils.msgpack._sanitize_msgpack_unpack_kwargs(kwargs),
+            {"use_bin_type": True},
+        )
+
+        kwargs = {"strict_map_key": True, "use_bin_type": True}
+        salt.utils.msgpack.version = (0, 4, 0)
+        self.assertEqual(
+            salt.utils.msgpack._sanitize_msgpack_unpack_kwargs(kwargs),
+            {"use_bin_type": True},
+        )
+        kwargs = {"strict_map_key": True, "use_bin_type": True}
+        salt.utils.msgpack.version = (0, 3, 0)
+        self.assertEqual(salt.utils.msgpack._sanitize_msgpack_unpack_kwargs(kwargs), {})
+        salt.utils.msgpack.version = version
+
     def _test_base(self, pack_func, unpack_func):
         '''
         In msgpack, 'dumps' is an alias for 'packb' and 'loads' is an alias for 'unpackb'.
