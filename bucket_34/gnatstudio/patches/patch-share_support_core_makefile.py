--- share/support/core/makefile.py.orig	2025-09-19 10:04:04 UTC
+++ share/support/core/makefile.py
@@ -185,20 +185,20 @@ class Makefile(Builder):
         # The list of targets at the beginning of a line. Ignore
         # special characters like #.= that are used by GNU make.
         # The list of targets is stored in the 'target' capturing group.
-        targets = "^(?P<targets>[^#.=%\t][^#=\(\)%]*?)"
+        targets = r"^(?P<targets>[^#.=%\t][^#=\(\)%]*?)"
 
         # The dependencies for these targets
-        deps = "[^#=:]*"
+        deps = r"[^#=:]*"
 
         # Extra comments at the ened of the line. Adding #IGNORE is used
         # to hide this target from GPS.
-        comments = "(?:#(?P<comments>.+))?$"
+        comments = r"(?:#(?P<comments>.+))?$"
 
         # It is valid for a target to be followed by two colons, in GNU
         # make at least.
-        self.target_matcher = re.compile(targets + "::?" + deps + comments)
+        self.target_matcher = re.compile(targets + r"::?" + deps + comments)
 
-        self.include_matcher = re.compile("^include (?P<file>.*)$")
+        self.include_matcher = re.compile(r"^include (?P<file>.*)$")
 
         self.current_dir = None
         # The directory of the toplevel makefile. All include statements
