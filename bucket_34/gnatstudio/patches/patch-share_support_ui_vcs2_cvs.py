--- share/support/ui/vcs2/cvs.py.orig	2025-09-19 10:04:04 UTC
+++ share/support/ui/vcs2/cvs.py
@@ -27,13 +27,13 @@ REV_HEADER = "revision "
 @core.register_vcs(default_status=GPS.VCS2.Status.UNTRACKED)
 class CVS(core_staging.Emulate_Staging, core.File_Based_VCS):
     __re_status = re.compile(
-        "^(?:"
-        + "(?:cvs status: Examining (?P<dir>.+))|"
-        + "(?:File: (?P<deleted>no file )?(?P<file>\S+)\s+"
-        + "Status: (?P<status>.+))|"
-        + "(?:\s+Working revision:\s*(?P<rev>[\d.]+).*)|"
-        + "(?:\s+Repository revision:\s*(?P<rrev>[\d.]+).*)"
-        + ")$"
+        r"^(?:"
+        + r"(?:cvs status: Examining (?P<dir>.+))|"
+        + r"(?:File: (?P<deleted>no file )?(?P<file>\S+)\s+"
+        + r"Status: (?P<status>.+))|"
+        + r"(?:\s+Working revision:\s*(?P<rev>[\d.]+).*)|"
+        + r"(?:\s+Repository revision:\s*(?P<rrev>[\d.]+).*)"
+        + r")$"
     )
 
     def _cvs(self, args, block_exit=False, spawn_console=False):
@@ -155,7 +155,7 @@ class CVS(core_staging.Emulate_Staging,
                 self.current = None
                 self.names = []
                 self.__re_log = re.compile(
-                    "^date: (?P<date>[^;]+);\s+author: (?P<author>[^;]+)"
+                    r"^date: (?P<date>[^;]+);\s+author: (?P<author>[^;]+)"
                 )
 
             def emit_previous(self, out_stream):
@@ -278,7 +278,7 @@ class CVS(core_staging.Emulate_Staging,
     @core.run_in_background
     def async_annotations(self, visitor, file):
         r = re.compile(
-            "^(?P<rev>\d+\.\d+)" "\s+\(" "(?P<author>\S+)" "\s+" "(?P<date>[^)]+)"
+            r"^(?P<rev>\d+\.\d+)" r"\s+\(" r"(?P<author>\S+)" r"\s+" "(?P<date>[^)]+)"
         )
         lines = []
         ids = []
