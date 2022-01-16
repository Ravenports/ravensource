--- main.c.orig	2022-01-11 03:15:32 UTC
+++ main.c
@@ -1446,6 +1446,12 @@ main_Init(int argc, char **argv)
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
