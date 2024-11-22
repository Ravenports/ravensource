--- share/plug-ins/dispatching.py.orig	2024-11-01 10:55:18 UTC
+++ share/plug-ins/dispatching.py
@@ -44,22 +44,14 @@ class Dispatching_Highlighter(Location_H
         GPS.Hook("preferences_changed").add(self.__on_preferences_changed)
         GPS.Hook("file_edited").add(self.__on_file_edited)
         GPS.Hook("file_changed_on_disk").add(self.__on_file_edited)
-
-        if GPS.Logger("ENTITIES.SQLITE").active:
-            GPS.Hook("xref_updated").add(self.__on_compilation_finished)
-        else:
-            GPS.Hook("compilation_finished").add(self.__on_compilation_finished)
+        GPS.Hook("compilation_finished").add(self.__on_compilation_finished)
 
     def __del__(self):
         Location_Highlighter.__del__(self)
         GPS.Hook("preferences_changed").remove(self.__on_preferences_changed)
         GPS.Hook("file_edited").remove(self.__on_file_edited)
         GPS.Hook("file_changed_on_disk").remove(self.__on_file_edited)
-
-        if GPS.Logger("ENTITIES.SQLITE").active:
-            GPS.Hook("xref_updated").remove(self.__on_compilation_finished)
-        else:
-            GPS.Hook("compilation_finished").remove(self.__on_compilation_finished)
+        GPS.Hook("compilation_finished").remove(self.__on_compilation_finished)
 
     def __on_preferences_changed(self, hook):
         changed = False
