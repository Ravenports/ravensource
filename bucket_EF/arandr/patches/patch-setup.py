--- setup.py.orig	2023-01-12 15:58:48 UTC
+++ setup.py
@@ -53,7 +53,9 @@ class NoOptionCommand(Command):
     """Command that doesn't take any options"""
     user_options = []
 
-    def initialize_options(self): pass
+    def initialize_options(self):
+        self.dry_run = 0
+
     def finalize_options(self): pass
 
 class update_pot(NoOptionCommand):
