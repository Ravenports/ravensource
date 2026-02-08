--- share/support/ui/vcs2/subversion.py.orig	2025-09-19 10:04:04 UTC
+++ share/support/ui/vcs2/subversion.py
@@ -14,8 +14,8 @@ CAN_RENAME = True
 @core.register_vcs(name="subversion", default_status=GPS.VCS2.Status.UNTRACKED)
 class SVN(core_staging.Emulate_Staging, core.File_Based_VCS):
     __re_status = re.compile(
-        "^(?P<status>....... .)\s+(?P<rev>\S+)\s+"
-        + "(?P<lastcommit>\S+)\s+(?P<author>\S+)\s+(?P<file>.+)$"
+        r"^(?P<status>....... .)\s+(?P<rev>\S+)\s+"
+        + r"(?P<lastcommit>\S+)\s+(?P<author>\S+)\s+(?P<file>.+)$"
     )
 
     @staticmethod
@@ -130,11 +130,11 @@ class SVN(core_staging.Emulate_Staging,
         """
 
         _re_log = re.compile(
-            "^r(?P<rev>\d+)"
-            + "\s\|\s"
-            + "(?P<author>[^\|]+)"
-            + "\s\|\s"
-            + "(?P<date>[^|]+)"
+            r"^r(?P<rev>\d+)"
+            + r"\s\|\s"
+            + r"(?P<author>[^\|]+)"
+            + r"\s\|\s"
+            + r"(?P<date>[^|]+)"
         )
 
         class line_to_block:
@@ -219,7 +219,7 @@ class SVN(core_staging.Emulate_Staging,
     @core.run_in_background
     def async_annotations(self, visitor, file):
         r = re.compile(
-            "^\s*(?P<rev>\d\S*)" "\s+" "(?P<author>\S+)" "\s+" "(?P<date>....-..-..)"
+            r"^\s*(?P<rev>\d\S*)" r"\s+" r"(?P<author>\S+)" r"\s+" r"(?P<date>....-..-..)"
         )
         lines = []
         ids = []
