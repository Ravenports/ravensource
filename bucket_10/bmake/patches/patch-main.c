--- main.c.orig	2020-10-10 17:53:00 UTC
+++ main.c
@@ -1239,6 +1239,12 @@ main(int argc, char **argv)
 	    Var_Set(".MAKE.PID", tmp, VAR_GLOBAL);
 	    snprintf(tmp, sizeof(tmp), "%u", getppid());
 	    Var_Set(".MAKE.PPID", tmp, VAR_GLOBAL);
+	    Var_Set(".MAKE.OS.NAME",          OSNAME,    VAR_GLOBAL);
+	    Var_Set(".MAKE.OS.VERSION",       OSVERSION, VAR_GLOBAL);
+	    Var_Set(".MAKE.OS.RELEASE",       OSRELEASE, VAR_GLOBAL);
+	    Var_Set(".MAKE.OS.MAJOR",         OSMAJOR,   VAR_GLOBAL);
+	    Var_Set(".MAKE.OS.ARCHITECTURE",  OSARCH,    VAR_GLOBAL);
+	    Var_Set(".MAKE.OS.ARCH.STANDARD", STDARCH,   VAR_GLOBAL);
 	}
 	if (makelevel > 0) {
 		char pn[1024];
