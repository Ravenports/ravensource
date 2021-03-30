--- node_modules/@npmcli/config/lib/index.js.orig	2021-03-29 18:53:05 UTC
+++ node_modules/@npmcli/config/lib/index.js
@@ -327,6 +327,9 @@ class Config {
 
     if (this.env.PREFIX) {
       this.globalPrefix = this.env.PREFIX
+      if (this.env.DESTDIR) {
+        this.globalPrefix = join(this.env.DESTDIR, this.globalPrefix)
+      }
     } else if (this.platform === 'win32') {
     // c:\node\node.exe --> prefix=c:\node\
       this.globalPrefix = dirname(this.execPath)
