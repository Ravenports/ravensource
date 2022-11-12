--- node_modules/node-gyp/lib/configure.js.orig	1985-10-26 08:15:00 UTC
+++ node_modules/node-gyp/lib/configure.js
@@ -15,7 +15,7 @@ if (win) {
 }
 
 function configure (gyp, argv, callback) {
-  var python
+  var python = '@PYTHONBIN@'
   var buildDir = path.resolve('build')
   var buildBinsDir = path.join(buildDir, 'node_gyp_bins')
   var configNames = ['config.gypi', 'common.gypi']
@@ -23,14 +23,7 @@ function configure (gyp, argv, callback)
   var nodeDir
   var release = processRelease(argv, gyp, process.version, process.release)
 
-  findPython(gyp.opts.python, function (err, found) {
-    if (err) {
-      callback(err)
-    } else {
-      python = found
-      getNodeDir()
-    }
-  })
+  getNodeDir()
 
   function getNodeDir () {
     // 'python' should be set by now
