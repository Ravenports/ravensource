$NetBSD: patch-gi_overrides_Gio.py,v 1.1 2026/01/06 08:41:40 adam Exp $

Work-around for: AttributeError: 'bool' object has no attribute 'islower'

--- gi/overrides/Gio.py.orig	2025-10-18 11:13:44 UTC
+++ gi/overrides/Gio.py
@@ -656,7 +656,7 @@ if GioPlatform:
             try:
                 name = original_attr.__name__[0]
             except (AttributeError, IndexError):
-                name = original_attr
+                name = attr
 
             # Fallback if we don't have the original name.
             if name.islower():
