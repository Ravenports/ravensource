--- shell/source/unix/exec/shellexec.cxx.orig	2021-04-28 16:17:45 UTC
+++ shell/source/unix/exec/shellexec.cxx
@@ -173,7 +173,7 @@ void SAL_CALL ShellExec::execute( const
         aBuffer.append(" --");
 #else
         // Just use xdg-open on non-Mac
-        aBuffer.append("/usr/bin/xdg-open");
+        aBuffer.append("%%LOCALBASE%%/bin/xdg-open");
 #endif
         aBuffer.append(" ");
         escapeForShell(aBuffer, OUStringToOString(aURL, osl_getThreadTextEncoding()));
