--- lib/execjs/runtimes.rb.orig	2021-05-28 20:23:01 UTC
+++ lib/execjs/runtimes.rb
@@ -17,7 +17,7 @@ module ExecJS
 
     Node = ExternalRuntime.new(
       name:        "Node.js (V8)",
-      command:     ["node", "nodejs"],
+      command:     ["node", "nodejs", "%%LOCALBASE%%/bin/node"],
       runner_path: ExecJS.root + "/support/node_runner.js",
       encoding:    'UTF-8'
     )
