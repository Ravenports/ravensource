--- share/support/core/gs_utils/__init__.py.orig	2025-09-19 10:04:04 UTC
+++ share/support/core/gs_utils/__init__.py
@@ -9,6 +9,7 @@ import GPS.Browsers
 
 # The autodoc may not have visibility on gi.repository
 try:
+    gi.require_version('Gtk', '3.0')
     from gi.repository import Gtk
 except Exception:
     pass
