--- shell/source/unix/exec/shellexec.cxx.orig	2020-12-09 18:56:14 UTC
+++ shell/source/unix/exec/shellexec.cxx
@@ -186,7 +186,7 @@ void SAL_CALL ShellExec::execute( const
         aBuffer.append(" --");
 #else
         // Just use xdg-open on non-Mac
-        aBuffer.append("/usr/bin/xdg-open");
+        aBuffer.append("%%LOCALBASE%%/bin/xdg-open");
 #endif
         aBuffer.append(" ");
         escapeForShell(aBuffer, OUStringToOString(aURL, osl_getThreadTextEncoding()));
