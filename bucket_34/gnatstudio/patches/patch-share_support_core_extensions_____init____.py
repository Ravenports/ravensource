--- share/support/core/extensions/__init__.py.intermediate	2025-11-11 06:41:01 UTC
+++ share/support/core/extensions/__init__.py
@@ -54,14 +54,14 @@ class extend_module:
 
                 if not hasattr(orig_class, name):
                     if is_override:
-                        GPS.Console().write(
+                        GPS.Console("jane").write(
                             "Method %s.%s is not overriding\n" % (class_name, name)
                         )
                     setattr(orig_class, name, method)
 
                 else:
                     if not is_override:
-                        GPS.Console().write(
+                        GPS.Console("jane").write(
                             "Method %s.%s is overriding, ignored\n" % (class_name, name)
                         )
                     else:
@@ -187,11 +187,11 @@ class EditorBuffer(object):
         """
         if not GPS.EditorBuffer.__warned_about_undo_redo:
             GPS.EditorBuffer.__warned_about_undo_redo = True
-            GPS.Console().write(
+            GPS.Console("jane").write(
                 "GPS.EditorBuffer.start_undo_group is deprecated:"
                 " use GPS.EditorBuffer.new_undo_group instead:\n\n"
             )
-            GPS.Console().write(self.new_undo_group.__doc__)
+            GPS.Console("jane").write(self.new_undo_group.__doc__)
         self._start_undo_group()
         if hasattr(self, "undo_group"):
             self.undo_group += 1
@@ -203,12 +203,12 @@ class EditorBuffer(object):
         global warned_about_undo_redo
         if not warned_about_undo_redo:
             warned_about_undo_redo = True
-            GPS.Console().write(
+            GPS.Console("jane").write(
                 "GPS.EditorBuffer.finish_undo_group is deprecated:"
                 " use GPS.EditorBuffer.new_undo_group instead.\n"
             )
         if not hasattr(self, "undo_group"):
-            GPS.Console().write(
+            GPS.Console("jane").write(
                 "Error: 'finish_undo_group' not matching 'start_undo_group'\n"
             )
         else:
@@ -216,7 +216,7 @@ class EditorBuffer(object):
             if self.undo_group >= 0:
                 self._finish_undo_group()
             else:
-                GPS.Console().write(
+                GPS.Console("jane").write(
                     "Error: more calls to 'finish_undo_group'"
                     " than to 'start_undo_group'\n"
                 )
@@ -565,7 +565,7 @@ class Menu(GPS.GUI):
         self.action.disable(False)
 
     def pywidget(self):
-        GPS.Console().write(
+        GPS.Console("jane").write(
             "GPS.Menu.pywidget is no longer supported."
             + " Use GPS.Menu.action to interacte with the action"
             + " directly"
@@ -625,7 +625,7 @@ class Menu(GPS.GUI):
         """
 
         if on_activate:
-            GPS.Console().write(
+            GPS.Console("jane").write(
                 'GPS.Menu.create("%s") is deprecated.' % path
                 + " Please use gs_utils.interactive()\n"
             )
