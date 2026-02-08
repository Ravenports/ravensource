--- share/support/core/shell.py.orig	2025-09-19 10:04:04 UTC
+++ share/support/core/shell.py
@@ -41,7 +41,7 @@ class Unix_Shell(ANSI_Console_Process):
         ANSI_Console_Process.__init__(self, command)
         if GPS.Preference("External Commands:Shell/stty").get():
             self.send(
-                'stty echo; PS1="\[\e[1G\]$PS1";'
+                r'stty echo; PS1="\[\e[1G\]$PS1";'
                 ' echo -en "\\e[1;"$(stty size | cut -d" " -f1)'
                 '";1;"$(stty size | cut -d" " -f2)"r";'
                 " clear"
