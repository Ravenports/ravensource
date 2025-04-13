--- node_modules/@npmcli/config/lib/index.js.orig	1985-10-26 08:15:00 UTC
+++ node_modules/@npmcli/config/lib/index.js
@@ -325,6 +325,9 @@ class Config {
 
     if (this.env.PREFIX) {
       this.globalPrefix = this.env.PREFIX
+      if (this.env.DESTDIR) {
+        this.globalPrefix = join(this.env.DESTDIR, this.globalPrefix)
+      }
     } else if (this.platform === 'win32') {
       // c:\node\node.exe --> prefix=c:\node\
       this.globalPrefix = dirname(this.execPath)
