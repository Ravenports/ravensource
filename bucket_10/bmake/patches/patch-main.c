--- main.c.orig	2020-12-26 03:56:05 UTC
+++ main.c
@@ -1461,6 +1461,12 @@ main_Init(int argc, char **argv)
 		Var_Set(".MAKE.UID", tmp, VAR_GLOBAL);
 		snprintf(tmp, sizeof tmp, "%u", getgid());
 		Var_Set(".MAKE.GID", tmp, VAR_GLOBAL);
+		Var_Set(".MAKE.OS.NAME",          OSNAME,    VAR_GLOBAL);
+		Var_Set(".MAKE.OS.VERSION",       OSVERSION, VAR_GLOBAL);
+		Var_Set(".MAKE.OS.RELEASE",       OSRELEASE, VAR_GLOBAL);
+		Var_Set(".MAKE.OS.MAJOR",         OSMAJOR,   VAR_GLOBAL);
+		Var_Set(".MAKE.OS.ARCHITECTURE",  OSARCH,    VAR_GLOBAL);
+		Var_Set(".MAKE.OS.ARCH.STANDARD", STDARCH,   VAR_GLOBAL);
 	}
 	if (makelevel > 0) {
 		char pn[1024];
