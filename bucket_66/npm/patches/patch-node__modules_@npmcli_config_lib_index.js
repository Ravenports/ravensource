--- node_modules/@npmcli/config/lib/index.js.orig	2021-03-24 21:11:31 UTC
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
