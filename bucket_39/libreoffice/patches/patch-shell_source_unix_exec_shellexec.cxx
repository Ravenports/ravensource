--- shell/source/unix/exec/shellexec.cxx.orig	2026-04-09 16:07:27 UTC
+++ shell/source/unix/exec/shellexec.cxx
@@ -190,7 +190,7 @@ void SAL_CALL ShellExec::execute( const
         aBuffer.append(" --");
 #else
         // Just use xdg-open on non-Mac
-        aBuffer.append("xdg-open");
+        aBuffer.append("%%LOCALBASE%%/bin/xdg-open");
 #endif
         aBuffer.append(" ");
         escapeForShell(aBuffer, OUStringToOString(aURL, osl_getThreadTextEncoding()));
