--- node_modules/node-gyp/lib/configure.js.orig	1985-10-26 08:15:00 UTC
+++ node_modules/node-gyp/lib/configure.js
@@ -24,7 +24,7 @@ async function configure (gyp, argv) {
   let nodeDir
   const release = processRelease(argv, gyp, process.version, process.release)
 
-  const python = await findPython(gyp.opts.python)
+  const python = '@PYTHONBIN@'
   return getNodeDir()
 
   async function getNodeDir () {
