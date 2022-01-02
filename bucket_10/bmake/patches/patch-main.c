--- main.c.orig	2021-12-21 18:47:38 UTC
+++ main.c
@@ -1483,6 +1483,12 @@ main_Init(int argc, char **argv)
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
