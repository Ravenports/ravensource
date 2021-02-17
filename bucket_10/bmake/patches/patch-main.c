--- main.c.orig	2021-02-05 20:02:57 UTC
+++ main.c
@@ -1472,6 +1472,12 @@ main_Init(int argc, char **argv)
 		Global_Set(".MAKE.UID", tmp);
 		snprintf(tmp, sizeof tmp, "%u", getgid());
 		Global_Set(".MAKE.GID", tmp);
+		Global_Set(".MAKE.OS.NAME",          OSNAME);
+		Global_Set(".MAKE.OS.VERSION",       OSVERSION);
+		Global_Set(".MAKE.OS.RELEASE",       OSRELEASE);
+		Global_Set(".MAKE.OS.MAJOR",         OSMAJOR);
+		Global_Set(".MAKE.OS.ARCHITECTURE",  OSARCH);
+		Global_Set(".MAKE.OS.ARCH.STANDARD", STDARCH);
 	}
 	if (makelevel > 0) {
 		char pn[1024];
