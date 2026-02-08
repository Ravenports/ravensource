--- share/support/ui/gnattest.py.orig	2025-09-19 10:04:04 UTC
+++ share/support/ui/gnattest.py
@@ -682,7 +682,7 @@ def is_supported_by_tgen(subp_spec):
 @interactive(
     "General",
     fuzz_subp_filter,
-    contextual="GNATtest/Start\/Stop fuzzing subprogram",
+    contextual=r"GNATtest/Start\/Stop fuzzing subprogram",
     name="gnattest fuzz subprogram",
     description="Fuzz suprogram using test cases as initial seeds",
     contextual_group=GPS.Contextual.Group.EXTRA_INFORMATION,
