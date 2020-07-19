--- shell/source/unix/exec/shellexec.cxx.orig	2020-07-15 18:21:20 UTC
+++ shell/source/unix/exec/shellexec.cxx
@@ -182,7 +182,7 @@ void SAL_CALL ShellExec::execute( const
         aBuffer.append(" --");
 #else
         // Just use xdg-open on non-Mac
-        aBuffer.append("/usr/bin/xdg-open");
+        aBuffer.append("%%LOCALBASE%%/bin/xdg-open");
 #endif
         aBuffer.append(" ");
         escapeForShell(aBuffer, OUStringToOString(aURL, osl_getThreadTextEncoding()));
