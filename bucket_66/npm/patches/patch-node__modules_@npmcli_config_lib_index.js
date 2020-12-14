--- node_modules/@npmcli/config/lib/index.js.orig	2020-12-14 04:21:15 UTC
+++ node_modules/@npmcli/config/lib/index.js
@@ -291,6 +291,9 @@ class Config {
 
     if (this.env.PREFIX) {
       this.globalPrefix = this.env.PREFIX
+      if (this.env.DESTDIR) {
+        this.globalPrefix = join(this.env.DESTDIR, this.globalPrefix)
+      }
     } else if (this.platform === 'win32') {
     // c:\node\node.exe --> prefix=c:\node\
       this.globalPrefix = dirname(this.execPath)
