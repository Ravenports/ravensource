--- gold/plugin.cc.orig	2018-06-24 18:38:57 UTC
+++ gold/plugin.cc
@@ -508,7 +508,9 @@ Plugin_recorder::init()
   // Create a temporary directory where we can stash the log and
   // copies of replacement files.
   char dir_template[] = "gold-recording-XXXXXX";
-  if (mkdtemp(dir_template) == NULL)
+  if (mktemp(dir_template) == NULL)
+    return false;
+  if (mkdir(dir_template, 0700) != 0)
     return false;
 
   size_t len = strlen(dir_template) + 1;
