--- main.c.orig	2023-01-02 17:45:54 UTC
+++ main.c
@@ -1431,6 +1431,12 @@ main_Init(int argc, char **argv)
 		Global_Set(".MAKE.UID", buf);
 		snprintf(buf, sizeof buf, "%u", getgid());
 		Global_Set(".MAKE.GID", buf);
+		Global_Set(".MAKE.OS.NAME",          OSNAME);
+		Global_Set(".MAKE.OS.VERSION",       OSVERSION);
+		Global_Set(".MAKE.OS.RELEASE",       OSRELEASE);
+		Global_Set(".MAKE.OS.MAJOR",         OSMAJOR);
+		Global_Set(".MAKE.OS.ARCHITECTURE",  OSARCH);
+		Global_Set(".MAKE.OS.ARCH.STANDARD", STDARCH);
 	}
 	if (makelevel > 0) {
 		char pn[1024];
