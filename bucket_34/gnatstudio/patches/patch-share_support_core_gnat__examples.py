--- share/support/core/gnat_examples.py.orig	2025-09-19 10:04:04 UTC
+++ share/support/core/gnat_examples.py
@@ -72,7 +72,7 @@ class GNATExamples(Module):
         """
 
         actions = []
-        title_regexp = re.compile("<title>GNAT \&prefix;(.+)</title>")
+        title_regexp = re.compile(r"<title>GNAT \&prefix;(.+)</title>")
 
         for subdir in glob.glob(os.path.join(example_directory, "*")) + glob.glob(
             os.path.join(example_directory, "*", "*")
