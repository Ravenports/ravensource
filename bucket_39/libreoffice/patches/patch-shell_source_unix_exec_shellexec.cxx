--- shell/source/unix/exec/shellexec.cxx.orig	2019-01-23 19:35:25 UTC
+++ shell/source/unix/exec/shellexec.cxx
@@ -138,7 +138,7 @@ void SAL_CALL ShellExec::execute( const
         aBuffer.append("open --");
 #else
         // Just use xdg-open on non-Mac
-        aBuffer.append("/usr/bin/xdg-open");
+        aBuffer.append("%%LOCALBASE%%/bin/xdg-open");
 #endif
         aBuffer.append(" ");
         escapeForShell(aBuffer, OUStringToOString(aURL, osl_getThreadTextEncoding()));
