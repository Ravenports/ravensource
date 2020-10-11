--- shell/source/unix/exec/shellexec.cxx.orig	2020-09-30 15:54:35 UTC
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
