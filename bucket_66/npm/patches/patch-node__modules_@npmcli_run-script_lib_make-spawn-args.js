--- node_modules/@npmcli/run-script/lib/make-spawn-args.js.orig	2022-09-13 23:13:51 UTC
+++ node_modules/@npmcli/run-script/lib/make-spawn-args.js
@@ -67,7 +67,7 @@ const makeSpawnArgs = options => {
   }
   const spawnArgs = isCmd
     ? ['/d', '/s', '/c', script]
-    : ['-c', '--', script]
+    : ['-c', script]
 
   const spawnOpts = {
     env: spawnEnv,
